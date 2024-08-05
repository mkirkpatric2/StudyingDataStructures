#include <stdio.h>
#include <stdlib.h>

//set struct and initialize first entry
struct node {
    int id;
    struct node *next;
};
struct node *head = NULL;

void newFrontNode(int id){
    //create link
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->id = id;
    //point to the old first node
    link->next = head;
    head=link;
}

void newEndNode(int id){
    //create link
    struct node *link = (struct node*)malloc(sizeof(struct node));
    link->id = id;
    link->next = NULL;

    //loop through til the next pointer is null (aka last entry) and set that next to link
    struct node *p = head;
    while (p->next != NULL){
        p=p->next;
    } p->next = link;
}
//enter in middle at index[id]
void middleNode(int id, int location){
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->id = id;

    //loop through to locate the nodes before and after the desired insertion
    //change pointer at index-1 to link
    //change pointer in link to old index [now index+1]
    struct node *p = head; int x;
    struct node *p2 = head;
    for(x=1;x<=location;x++)p2=p2->next;
    for(x=1;x<location;x++)p=p->next;
    p->next = link;
    link->next = p2;
}
// print list in order
void printList(void){
    struct node *p = head;
    printf("\n [");
    while (p != NULL){
        printf("-%d-", p->id);
        p=p->next;
    }
    printf("]\n");
}

//remove entry from the front
void removeEntryFromFront(void){
    //head is the first node
    //set head to the second node
    struct node *p = head;
    head = p->next;

    //remove pointer from old head to now-new-head
    //not necessary?? maybe good practice? Idk.
    p->next = NULL;
}

void removeEntryFromEnd(void){
    struct node *p = head;

    //loop through until end-1 node and set its pointer to NULL
    while (p->next->next != NULL){
        p=p->next;
    }
    p->next = NULL;

}

void removeEntryFromIndex(int index){
    struct node *p = head; int x;

    //loop through to [index to be removed]-1
    for(x=1;x<index;x++)p=p->next;
    //set its pointer to [index to be removed] + 1
    p->next = p->next->next;
}

int findValueAtIndex(int index){ //returns ID
    struct node *p = head;int x;

    //loop through to desired point and print id
    for (x=0;x<index;x++){
        p=p->next;
    }
    return p->id;
}
int isValueInList(int value){ // returns 0/1 bool
    struct node *p = head;int x=0;

    //loop until value found or end of list
    while (p!=NULL && x==0) {
        if (p->id == value)
            x++;
        p = p->next;
    }
    if (x>0)return 1;
    else return 0;
}

void printPresence(int value){
    int check = isValueInList(value);
    if (check)
        printf("\nValue %d is in the list\n", value);
    else
        printf("\nValue %d is NOT in the list\n", value);
}
int quantValueInList(int value){ // returns quantity of value
    struct node *p = head;int x=0;
    while (p!=NULL) {
        if (p->id == value)x++;
        p = p->next;
    }
    return x;
}

void printQuant(int value){
    int quant = quantValueInList(value);

    printf("\nValue %d is in the list %d times\n", value, quant);

}

int main() {
    newFrontNode(7);
    newFrontNode(6);
    newFrontNode(5);
    newFrontNode(4);
    newFrontNode(3);
    newFrontNode(5);
    newFrontNode(4);
    newFrontNode(3);
    newEndNode(9999);
    printList();
    middleNode(2222, 2);
    printList();
    removeEntryFromFront();
    printList();
    removeEntryFromEnd();
    printList();
    removeEntryFromIndex(2);
    printList();
    printf("\nValue at index 2 - %d\n",findValueAtIndex(2));
    printList();
    printPresence(7);
    printPresence(23232);
    newFrontNode(5);
    newFrontNode(4);
    newFrontNode(3);
    newFrontNode(5);
    newFrontNode(4);
    newFrontNode(3);
    printList();
    printQuant(3);
    printQuant(7);
    printQuant(422);



}
