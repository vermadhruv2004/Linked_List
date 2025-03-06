// WAP to display circular Linked List by inserting Node at left side.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}
*first=NULL;

void create(int value){
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;

    if(first==NULL){             // Case when the list is empty
        first=t;
        first->next=t;           // Link to itself, making it circular
    }

    else{
        struct Node *p= first;

        while(p->next!=first){    // Traverse to the last node (the node that points to the first)
            p=p->next;
        }

        t->next = first;          // New node points to the first
        p->next = t;             // Last node now points to the new node
        first = t;                // Move first to the new node
    }
}

void display(struct Node *p){
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=first);
}

int main(){
    int n,value;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Circular Linked list is :\n");
    display(first);

    return 0;
}

