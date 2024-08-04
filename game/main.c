#include <stdio.h>
#include <time.h>
#include "movement2.h"
#include "print2.h"
#include "monsterMovement.h"
#include "structs.h"
#include <stdint.h>
#include "weapons.h"

//replace with #include<unistd.h> for POSIX. Change sleep function to reflect
// SECONDS not MILLISECONDS
#include <windows.h>



void writeMap(struct cell a[35][35]){
    FILE *fp = fopen("map.txt", "w");
    int row,col;

    for (row=0; row<35; row++) {
        for (col = 0; col < 35; col++) {
            if (a[row][col].walkable == 0)fprintf(fp, "X ");
            else if (a[row][col].player==1)fprintf(fp, "1 ");
            else if (a[row][col].isSlime==1)fprintf(fp, "E ");
            else if (a[row][col].isSlime==-1)fprintf(fp, "s ");
            else if (a[row][col].hasWeapon==1)fprintf(fp, "W ");
            else if (a[row][col].walkable == 1)fprintf(fp, "_ ");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
//    printf("map saved!\n");
}



void buildMap(struct cell a[35][35]){
    int row, col;
    //populate top 2 and bottom 2 rows
    for (row=0;row<2;row++){for (col=0;col<35;col++){
        a[row][col].walkable = 0;
    }}
    for (row=34;row>32;row--){for (col=0;col<35;col++){
        a[row][col].walkable = 0;
    }}
    //populate left 2 and right 2 cols
    for (col=0;col<2;col++){for (row=2;row<33;row++){
        a[row][col].walkable = 0;
    }}
    for (col=34;col>32;col--){for (row=2;row<33;row++){
        a[row][col].walkable = 0;
    }}
    //populate middle walkable
    for(col=2;col<33;col++){
        for(row=2;row<33;row++){
            a[row][col].walkable = 1;
            a[row][col].player = 0;
            a[row][col].isSlime = 0;
            a[row][col].hasWeapon = 0;
        }
    }

//    writeMap(a);
}

int battleCheck=0;
void action(struct cell a[35][35], int ind[2]){
    int dir = getMove();
    int y = ind[0];
    int x = ind[1];
    movePlayer(a, ind, dir, y, x);
    printMap(a, ind);
    battleCheck = slimeBattle(a, ind);
    Sleep(700);
    moveAllMonsters(a);
    if (!battleCheck){
        slimeBattle(a, ind);
    }

    //move all monsters except current battle


    //check for slime battle again IF no slimebattle?

}

void startGame(struct cell a[35][35], int ind[2]){

    a[ind[0]][ind[1]].player=1;
    printMap(a, ind);
    action(a, ind);
    writeMap(a);
    //give option to move

}

void spawnStartingMonsters(struct cell a[35][35], int ind[2], int count){
    int z;
    for (z=0;z<count;z++){
        int y = (rand() % 30) +2;
        int x = (rand() % 30) +2;
        if (y==ind[0]&&x==ind[1]){
            //do nothing
        } else {
            generateSlime(a, y, x);
        }
    }
}


int main(void){
    srand(time(NULL)); //set random seed for monster movement and other future use cases
    struct weaponTable *table = createWeaponTable();
    populateWeapons(table);
    int index[2] = {3, 3};
    struct cell a[35][35];
    buildMap(a);
    spawnStartingMonsters(a, index, 15);
    spawnWeapon(a, table);
    startGame(a, index);


    while (player.hp>0){
        printMap(a, index);
        action(a, index);
    }

    printf("\nyou died\n");

    destroyTable(table);


}

