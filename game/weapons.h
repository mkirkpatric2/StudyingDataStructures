//
// Created by M on 7/31/2024.
//

#ifndef MINIGAMEV2_WEAPONS_H
#define MINIGAMEV2_WEAPONS_H
#include "combat2.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

uint32_t djb33_hash(const char* s, size_t len)
{
    uint32_t h = 5381;
    while (len--) {
        /* h = 33 * h ^ s[i]; */
        h += (h << 5);
        h ^= *s++;
    } return h;
}

struct weaponTable *createWeaponTable(void){
    struct weaponTable *table = (struct weaponTable *)malloc(sizeof(struct weaponTable));
    table->length = 0;   //initially no items
    table->capacity = 16;//initially 16 total slots available

    //allocate array space
    table->entries = calloc(table->capacity, sizeof(struct weapon));
    if (table->entries == NULL){
        free(table);
        return NULL;
    }
    return table;
}

void destroyTable(struct weaponTable *table){
    //free the existing keys
    for (int i = 0; i < table->capacity; i++){ //
        free((void *)table->entries[i].key); //confused about why I have to cast to null...
    }
    //free the array of entries and then the table
    free(table->entries);
    free(table);
}

char *addWeapon(struct weapon *entries, int capacity, char *key, size_t len, int str, int decay){
    uint32_t hash = djb33_hash(key, len);
    int index = hash%16; int i=0; int y=0;

    while (entries[index].key != NULL && y<2){
        if (strcmp(key, entries[index].key)==0){
            //key already exists. update value
            entries[index].str=str;
        }
        //entry occupied w/ diff key
        index++;

        // reached end of index. reset to 0 [situation: index is 15, its full, linear probe to 16 but 16 is not in array.go to 0]
        if (index >=capacity) {
            index = 0;
            y++;
            //loops infinitely if the array is 100% full, but I'm hardcoding it to never be full.
        }
    }
    entries[index].key = key;
    entries[index].str = str;
    entries[index].decay = decay;
    entries[index].len = len;
    return key;
}
char *weaponSetter(struct weaponTable *table, char *key, int len, int str, int decay){
    char *toReturn = addWeapon(table->entries, table->capacity, key, len, str, decay);
    return toReturn;
}

int getWepStr(char *key, int len, struct weaponTable *table){
    uint32_t hash = djb33_hash(key, len);
    size_t index = (size_t)(hash%16);

    while (table->entries[index].key != key && index < 16) {
        index++;
    }
    if (table->entries[index].key == key){
        return table->entries[index].str;
    }
    return 0;
}
void populateWeapons(struct weaponTable *table){
    weaponSetter(table, "knife", 5, 2, 1);
    weaponSetter(table, "hammer", 6, 2, 1);
    weaponSetter(table,"club", 4, 2, 1);
    weaponSetter(table,"sword", 5, 4, 1);
    weaponSetter(table,"gloves", 6, 3, 1);
    weaponSetter(table,"claws", 5, 3, 1);
    weaponSetter(table,"dagger", 3, 6, 1);
    weaponSetter(table,"wand", 4, 4, 1);

    printf("Successfully loaded weapons.\n");
}

void spawnWeapon(struct cell a[35][35], struct weaponTable *table){
    int x = 0;
    int i = rand()%16;
    //int spawnCell[2] = {rand()%31+2, rand()%31+2};
    int spawnCell[2] = {5, 5};
    while(!table->entries[i].str && x<2){ //don't create an infinite loop if the table isn't populated
        i++;
        if (i==16){
            i=0;x++;
        }
    }
    a[spawnCell[0]][spawnCell[1]].hasWeapon=1;
    a[spawnCell[0]][spawnCell[1]].weapon=&table->entries[i];
    printf("\nPosted weapon %s"
           " to cell %d %d\n", a[spawnCell[0]][spawnCell[1]].weapon->key,
           spawnCell[0], spawnCell[1]);
}
void checkDurability(){
    if (player.weapon->decay==0){
        player.weapon->str = 0;
        player.weapon->key = "";
        player.weapon->len = 0;
    }
}

#endif //MINIGAMEV2_WEAPONS_H
