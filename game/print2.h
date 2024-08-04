//
// Created by M on 7/31/2024.
//

#ifndef MINIGAMEV2_PRINT2_H
#define MINIGAMEV2_PRINT2_H
#include <stdio.h>
#include "movement2.h"
#include "print2.h"
#include "combat2.h"
#include "weapons.h"
#include "monsterMovement.h"
#include "structs.h"

void printBreak(void){
    printf("\n-----------------------\n");
}

void printMap(struct cell a[35][35], int ind[2]){
    int row, col;



    for (row=ind[0]-2; row<ind[0]+3; row++){

        for (col = ind[1]-2; col < ind[1]+3; col++) {
            if (a[row][col].walkable == 0)printf("X ");
            else if (a[row][col].player==1)printf("1 ");
            else if (a[row][col].isSlime==1)printf("E ");
            else if (a[row][col].isSlime==-1)printf("s ");
            else if (a[row][col].hasWeapon==1)printf("W ");
            else if (a[row][col].walkable == 1)printf("_ ");
        }
        printf("\n");
    }

    printBreak();
}

#endif //MINIGAMEV2_PRINT2_H
