// WAP to implement search by performing move to front operation in a Node by inserting Node at left side.

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
    t->next=first;
    first=t;
}

struct Node *(search(struct Node *p, int key)){

    struct Node *q=NULL;

    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int n,value,key;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Enter the key to search\n");
    scanf("%d", &key);

    struct Node *temp=search(first,key);

    if(temp){
        printf("Key is found %d\n", temp->data);
    }

    else{
        printf("Key is not found\n");
    }

    printf("Linked List is:\n");
    display(first);

    return 0;
}