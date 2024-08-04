//
// Created by M on 7/31/2024.
//

#ifndef MINIGAMEV2_MONSTERMOVEMENT_H
#define MINIGAMEV2_MONSTERMOVEMENT_H
#include "movement2.h"
#include "structs.h"




void generateSlime(struct cell a[35][35], int row, int col){
    struct slime *sp = (struct slime *)malloc(sizeof (struct slime)); //row
    if (a[row][col].isSlime == 0 && a[row][col].player == 0 && a[row][col].walkable == 1){
        sp->att = 2;
        sp->hp = 15;
        sp->nextSlime = slimeHead;
        slimeHead = sp;
        sp->ind[0] = row;
        sp->ind[1] = col;
        a[row][col].isSlime = 1;
        a[row][col].slime = sp;
    }
}

void moveOneMonster(struct cell a[35][35], struct slime *sp, int count){

    int y = (rand() % 9) +1 ; //generate random number between 1-9
    //printf("Monster %d roll %d\n",count, y);


    if (a[sp->ind[0]][sp->ind[1]].player == 1 || sp->hp<1){
        //don't move
    }else switch(y){
        case 5:
            break;

        case 1:
            if (a[sp->ind[0]-1][sp->ind[1]-1].walkable==1 && a[sp->ind[0]-1][sp->ind[1]-1].isSlime==0){
                a[sp->ind[0]-1][sp->ind[1]-1].isSlime = 1;
                a[sp->ind[0]][sp->ind[1]].isSlime = 0;
                a[sp->ind[0]-1][sp->ind[1]-1].slime = a[sp->ind[0]][sp->ind[1]].slime;
                a[sp->ind[0]][sp->ind[1]].slime = NULL;
                sp->ind[0]--;
                sp->ind[1]--;
            }
            break;

        case 2:

            if (a[sp->ind[0]-1][sp->ind[1]].walkable==1 && a[sp->ind[0]-1][sp->ind[1]].isSlime==0){
                a[sp->ind[0]-1][sp->ind[1]].isSlime = 1;
                a[sp->ind[0]][sp->ind[1]].isSlime = 0;
                a[sp->ind[0]-1][sp->ind[1]].slime = a[sp->ind[0]][sp->ind[1]].slime;
                a[sp->ind[0]][sp->ind[1]].slime = NULL;
                sp->ind[0]--;
            }
            break;

        case 3:
            if (a[sp->ind[0]-1][sp->ind[1]+1].walkable==1 && a[sp->ind[0]-1][sp->ind[1]+1].isSlime==0){
                a[sp->ind[0]-1][sp->ind[1]+1].isSlime = 1;
                a[sp->ind[0]][sp->ind[1]].isSlime = 0;
                a[sp->ind[0]-1][sp->ind[1]+1].slime = a[sp->ind[0]][sp->ind[1]].slime;
                a[sp->ind[0]][sp->ind[1]].slime = NULL;
                sp->ind[0]--;
                sp->ind[1]++;
            }

            break;

        case 4:
            if (a[sp->ind[0]][sp->ind[1]-1].walkable==1 && a[sp->ind[0]][sp->ind[1]-1].isSlime==0){
                a[sp->ind[0]][sp->ind[1]-1].isSlime = 1;
                a[sp->ind[0]][sp->ind[1]].isSlime = 0;
                a[sp->ind[0]][sp->ind[1]-1].slime = a[sp->ind[0]][sp->ind[1]].slime;
                a[sp->ind[0]][sp->ind[1]].slime = NULL;
                sp->ind[1]--;
            }
            break;

        case 6:
            if (a[sp->ind[0]][sp->ind[1]+1].walkable==1 && a[sp->ind[0]][sp->ind[1]+1].isSlime==0){
                a[sp->ind[0]][sp->ind[1]+1].isSlime = 1;
                a[sp->ind[0]][sp->ind[1]].isSlime = 0;
                a[sp->ind[0]][sp->ind[1]+1].slime = a[sp->ind[0]][sp->ind[1]].slime;
                a[sp->ind[0]][sp->ind[1]].slime = NULL;
                sp->ind[1]++;
            }
            break;

        case 7:
            if (a[sp->ind[0]+1][sp->ind[1]-1].walkable==1 && a[sp->ind[0]+1][sp->ind[1]-1].isSlime==0){
                a[sp->ind[0]+1][sp->ind[1]-1].isSlime = 1;
                a[sp->ind[0]][sp->ind[1]].isSlime = 0;
                a[sp->ind[0]+1][sp->ind[1]-1].slime = a[sp->ind[0]][sp->ind[1]].slime;
                a[sp->ind[0]][sp->ind[1]].slime = NULL;
                sp->ind[0]++;
                sp->ind[1]--;
            }
            break;

        case 8:
            if (a[sp->ind[0]+1][sp->ind[1]].walkable==1 && a[sp->ind[0]+1][sp->ind[1]].isSlime==0){
                a[sp->ind[0]+1][sp->ind[1]].isSlime = 1;
                a[sp->ind[0]][sp->ind[1]].isSlime = 0;
                a[sp->ind[0]+1][sp->ind[1]].slime = a[sp->ind[0]][sp->ind[1]].slime;
                a[sp->ind[0]][sp->ind[1]].slime = NULL;
                sp->ind[0]++;
            }
            break;

        case 9:
            if (a[sp->ind[0]+1][sp->ind[1]+1].walkable==1 && a[sp->ind[0]+1][sp->ind[1]+1].isSlime==0){
                a[sp->ind[0]+1][sp->ind[1]+1].isSlime = 1;
                a[sp->ind[0]][sp->ind[1]].isSlime = 0;
                a[sp->ind[0]+1][sp->ind[1]+1].slime = a[sp->ind[0]][sp->ind[1]].slime;
                a[sp->ind[0]][sp->ind[1]].slime = NULL;
                sp->ind[0]++;
                sp->ind[1]++;
            }
            break;

        default:
            //stay still, inc. 5 press.
            break;
//

}}

void moveAllMonsters(struct cell a[35][35]){
    struct slime *sp = slimeHead;
    int count = 0;
    while (sp!=NULL){
        count++;
        moveOneMonster(a, sp, count);
        sp = sp->nextSlime;
    }
}
#endif //MINIGAMEV2_MONSTERMOVEMENT_H
