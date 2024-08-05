#include <stdio.h>
#include <stdlib.h>

//set struct and initialize first entry
struct node {
    int id;
    struct node *next;
};
struct node *head;
struct node *tail;

void firstNode(int id){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->id = id;
    p->next = p;
    head=p;
    tail=p;
}

void newNode(int id){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->id = id;
    p->next = head;
    head=p;
    tail->next = p;
}

void printNodes(int amount){
    struct node *p = tail;
    printf("[");
    for (int i = 0; i<amount; i++){
        //shifting the node first results in printing new->old entries
        //LIFO, But it does loop around if amount > # in list
        p = p->next;
        printf("-%d-", p->id);
    }
    printf("]\n");
}



int main() {
    firstNode(22);
    newNode(234);
    newNode(14);
    newNode(2354);
    newNode(51);
    printNodes(4);
    printNodes(12);

}
