//
// Created by M on 7/31/2024.
//

#ifndef MINIGAMEV2_STRUCTS_H
#define MINIGAMEV2_STRUCTS_H



struct player{
    int hp;
    int att;
    struct weapon *weapon;
};
struct player player ={25, 4, NULL};

struct cell {
    int walkable;
    int isSlime;
    struct slime *slime; //pointer to struct: hp and att
    int player;
    int hasWeapon;
    struct weapon *weapon;
};


struct combatTurn {
    int isPlayer;
    struct combatTurn *next;
};

struct slime{
    int hp;
    int att;
    int ind[2]; // [row, col]
    struct slime *nextSlime;
};
struct slime *slimeHead = NULL;

struct weapon{
    const char* key;
    int str;
    size_t len;
    int decay;
};

struct weaponTable{
    struct weapon *entries; //actual hash slots
    int capacity; // size of entries array.
    int length; //number of items in hash table
};




#endif //MINIGAMEV2_STRUCTS_H
