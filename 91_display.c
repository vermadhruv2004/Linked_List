#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;    // Pointer to the next Node
    int data;             // Data of the Node
    struct Node *next;    // Pointer to the prev Node
}
*first=NULL, *last=NULL;  // Pointer to the first and the last Node in the List.

void create(int value){
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;
    t->next=NULL;
    t->prev=last;   // Set the prev pointer to the current last Node.

    if(first==NULL){    // If the list is Empty, initialize it...
        first=t;
        last=t;
    }
    else{
        last->next=t;      // Otherwise add the new Node at the end.
        last=t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int n,value;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    display(first);

    return 0;
}