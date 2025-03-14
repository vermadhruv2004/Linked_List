// WAP to implement linear search using multiple keys by inserting Nodes at Right side.

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

    if(first==NULL){
        first=t;
        last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

struct Node *(search(struct Node *p, int key)){

    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int main(){
    int n,value,key;
    printf("Enter the no of elements in a LL\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list is :\n");
    display(first);
    printf("\n");

    char choice;
    do{
        printf("Enter the key to search\n");
        scanf("%d", &key);
        
        struct Node *temp=search(first,key);

        if(temp){
            printf("%d key is found\n", temp->data);
        }
        else{
            printf("Key is not found\n");
        }

        printf("Do you want to search for another key? (y/n): ");
        scanf(" %c", &choice);
    }
    while(choice=='y' || choice=='y');

    return 0;
}