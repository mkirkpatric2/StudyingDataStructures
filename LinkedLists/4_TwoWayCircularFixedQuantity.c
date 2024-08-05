#include <stdio.h>
#include <stdlib.h>

//set struct and initialize first entry
struct node {
    int data;
    struct node *next;
    struct node *prior;
    int consumed;
};
struct node *head;

//make 10 empty nodes in a circle.
void generateEmptyNodes(){
    for (int i = 0; i<10; i++){
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->consumed=0;
        p->data=999999; //terminal value to demonstrate lack of entry of data
        p->next = head;
        p->prior = NULL;
        if (head!=NULL){
            head->prior = p;
        }
        head = p;
    }
    struct node *sp = head;
    while (sp->next != NULL){
        sp=sp->next;
    }
    head->prior = sp;
    sp->next = head;
}

void updateValue(int data){
    struct node *p = head;
    p->data=data;
    //reset consumption status
    p->consumed = 0;
    head=head->next;
}

void printNodesNext(int amount){
    struct node *p = head;
    printf("[");
    for (int i = 0; i<amount; i++){

        if (p->data!=999999){
            printf("-%d-", p->data);
            p = p->next;
        } else p = p->next;
    }
    printf("]\n");
}

void printNodesPrior(int amount){
    struct node *p = head;
    printf("[");
    for (int i = 0; i<amount; i++){

        if (p->data!=999999){
            printf("-%d-", p->data);
            p = p->prior;
        } else p = p->prior;
    }
    printf("]\n");
}



void consumeList(int a[10]){
    struct node *p = head->prior;
    for (int i = 0;i<10;i++){
        if (p->consumed==0){
            p->consumed=1;
            a[i]=p->data;
            p = p->prior;

        } else {
            a[i]=0;
            p = p->prior;
        }
    }
}



int main() {
    generateEmptyNodes();
    updateValue(4);
    updateValue(5);
    updateValue(6);
    updateValue(14);
    updateValue(11);
    updateValue(15);
    updateValue(19);
    updateValue(22);
    updateValue(24);
    updateValue(26);
    updateValue(28);
    updateValue(31);
    updateValue(33);
    updateValue(37);
    printNodesNext(20);
    printNodesPrior(20);

    int a[10];
    consumeList(a);
    for(int z=0;z<10;z++){
        if (a[z])printf("_%d index of array is %d_\n", z, a[z]);
    }

    updateValue(28);
    updateValue(31);
    updateValue(33);
    printNodesNext(20);
    printNodesPrior(20);

    int b[10];
    consumeList(b);
    for(int z=0;z<10;z++){
        if (b[z])printf("_%d index of array is %d_\n", z, b[z]);
    }


}
