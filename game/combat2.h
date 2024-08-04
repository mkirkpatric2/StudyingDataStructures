//
// Created by M on 7/31/2024.
//

#ifndef MINIGAMEV2_COMBAT2_H
#define MINIGAMEV2_COMBAT2_H
#include <stdlib.h>
#include "monsterMovement.h"
#include "structs.h"
#include "weapons.h"

struct combatTurn *head;

void addTurn(int isPlayer){
    struct combatTurn *p = (struct combatTurn*)malloc(sizeof(struct combatTurn));
    p->isPlayer=isPlayer;
    p->next=head;
    head=p;
}
void printTurnsTest(){ // out of commission for now, was used in testing the created stack
    struct combatTurn *p = head;
    while (p != NULL){
        printf("\nis player: %d\n", p->isPlayer);
        p=p->next;
    }
    printf("\nturns done!\n");
}

void consumeTurns(struct player *p, struct slime *s){
    struct combatTurn *turn = head;


    while(turn!=NULL){
        if (p->hp < 1 || s->hp < 1){ //do nothing - someone is dead
        } else if (turn->isPlayer==1){
            s->hp = s->hp - (p->att + p->weapon->str);
            printf("You attacked for %d damage, slimeHP = %d\n", (p->att + p->weapon->str), s->hp);
            player.weapon->decay--;
            checkDurability();
        } else {
            //slime's combatTurn
            p->hp = p->hp - s->att;
            printf("Slime attacked for %d damage, playerHP = %d\n", s->att, p->hp);
        }

        struct combatTurn *toFree = turn;
        turn = turn->next;
        head = turn;
        free(toFree);
    }
    if(s->hp>0)printf("\nThe slime yet lives....\n\n");
    else {
        printf("You murdered the slime\n\n");
        //pop slime off list? Or keep on list as dead. haven't decided.
    };


}



#endif //MINIGAMEV2_COMBAT2_H
