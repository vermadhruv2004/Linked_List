// WAP to display circular Linked List by inserting Node at left side.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}
*first=NULL, *last=NULL;


void create(int value){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;
    t->next=NULL;

    if(first==NULL){       // If list is empty
        first=t;
        last=t;
        last->next=first;         // Make it circular
    }
    else{
        last->next=t;         // Last node now points to the new first
        t->next=first;         // New node points to the current first
        first=t;               // Update first to new node
    }
}

void Rdisplay(struct Node *p){

    static int flag=0;
    if(p!=first || flag==0){
        flag=1;
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
    flag=0;
}

int main(){
    int n,value;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);\
        scanf("%d", &value);
        create(value);
    }

    printf("Circular linked list is : \n");
    Rdisplay(first);

    return 0;
}