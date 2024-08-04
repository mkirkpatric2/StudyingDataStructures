//
// Created by M on 7/31/2024.
//

#ifndef MINIGAMEV2_MOVEMENT2_H
#define MINIGAMEV2_MOVEMENT2_H
#include <stdio.h>
#include "combat2.h"
#include "structs.h"



int getMove(void){
    printf("Please select the direction (integer) you'd like to go: \n");
    printf("__123__\n");printf("__4X6__\n");printf("__789__\n\n");
    int dir = 0;
    int check = scanf("%d", &dir);

    while(check == 0){
        printf("error\nPlease try again(1-4, 6-9):\n");
        char dummyc; float dummyf;
        scanf("%c", &dummyc);
        scanf("%f", &dummyf);
        check = scanf("%d", &dir);
    }
    return dir;
}

void movePlayer(struct cell a[35][35], int ind[2], int dir, int y, int x){
    switch(dir){
        case 1:
            if (a[y-1][x-1].walkable==1){
                ind[0]--;
                ind[1]--;
                a[y-1][x-1].player = 1;
                a[y][x].player = 0;
            } else printf("invalid\n\n");
            break;

        case 2:

            if (a[y-1][x].walkable==1){
                ind[0]--;
                a[y-1][x].player = 1;
                a[y][x].player = 0;
            } else printf("invalid\n\n");
            break;

        case 3:
            if (a[y-1][x+1].walkable==1){
                a[y][x].player=0;
                a[y-1][x+1].player=1;
                ind[1]++;
                ind[0]--;
            }else printf("invalid\n\n");
            break;

        case 4:
            if (a[y][x-1].walkable==1){
                ind[1]--;
                a[y][x-1].player = 1;
                a[y][x].player = 0;
            } else printf("invalid\n\n");
            break;

        case 6:
            if (a[y][x+1].walkable==1){
                a[y][x+1].player = 1;
                a[y][x].player = 0;
                ind[1]++;
            } else printf("invalid\n\n");
            break;;

        case 7:
            if (a[y+1][x-1].walkable==1){
                a[y][x].player=0;
                a[y+1][x-1].player=1;
                ind[1]--;
                ind[0]++;
            }else printf("invalid\n\n");
            break;

        case 8:
            if (a[y+1][x].walkable==1){
                ind[0]++;
                a[y+1][x].player = 1;
                a[y][x].player = 0;
            } else printf("invalid\n\n");
            break;

        case 9:
            if (a[y+1][x+1].walkable==1){
                ind[0]++;
                ind[1]++;
                a[y+1][x+1].player = 1;
                a[y][x].player = 0;
            } else printf("invalid\n\n");
            break;

        case 5:
            //stay still
            break;

        default:
            printf("invalid entry - 1,2,3,4,6,7,8,9 ONLY\nTry Again\n");
            break;

    }
    printf("%d down, %d right\n", ind[0], ind[1]);
}

void weaponPickup(struct cell a[35][35], int ind[2]){
    if (a[ind[0]][ind[1]].player==1 && a[ind[0]][ind[1]].hasWeapon==1) {
        //set new pointer to weapon stats
        struct weapon *wp = (struct weapon *)malloc(sizeof(struct weapon));
        wp->str = a[ind[0]][ind[1]].weapon->str;
        wp->key = a[ind[0]][ind[1]].weapon->key;
        wp->decay = a[ind[0]][ind[1]].weapon->decay;
        wp->len = a[ind[0]][ind[1]].weapon->len;

        //create pointer for old user weapon to then free.
        struct weapon *oldWep = player.weapon;
        //assign new weapon to player. Don't want to override weapon info in hashmap
        player.weapon = wp;
        //free old wep -- is this necessary? not for the first pickup but all subsequent?
        free(oldWep);

        //reset cell data
        a[ind[0]][ind[1]].hasWeapon = 0;
        a[ind[0]][ind[1]].weapon = NULL;
        printf("Player picked up %s and added %d str\n", player.weapon->key, player.weapon->str);
    }
}

int slimeBattle(struct cell a[35][35], int ind[2]){

    int z;
    if (a[ind[0]][ind[1]].player==1 && a[ind[0]][ind[1]].isSlime==1){
        for (z=0;z<6;z++){
            if (z%2==0){
                addTurn(0);
            } else {
                addTurn(1);
            }
        }

        consumeTurns(&player, a[ind[0]][ind[1]].slime); //how do we make dynamic slimes spawn


        if (player.hp<1)a[ind[0]][ind[1]].player=0; //player dead

        if (a[ind[0]][ind[1]].slime->hp<1)a[ind[0]][ind[1]].isSlime=-1;

        return 1;

    } else if (a[ind[0]][ind[1]].player==1 && a[ind[0]][ind[1]].isSlime==-1){
        printf("Nothing here but a dead slime.\n");

        return 1; //because slime can't occupy this space.
    }
    weaponPickup(a, ind);

    return 0;
}




#endif //MINIGAMEV2_MOVEMENT2_H
