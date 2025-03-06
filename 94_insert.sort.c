#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}
*first=NULL, *last=NULL;

void create(int value){
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=value;
    t->next=NULL;
    t->prev=last;

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

void insertsort(struct Node *p, int index, int x){

    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;

    while(p->next!=NULL && p->next->data<x){
        p=p->next;
    }

    if(p==first){
        temp->next=first;
        temp->prev=NULL;
        first->prev=temp;
        first=temp;
    }
    else{
        if(p){
            temp->next=p->next;
            temp->prev=p;
            if(p->next){
                p->next->prev=temp;
            }
            p->next=temp;
        }
        
    }
}


int main(){
    int n,value,index,x;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list before insertion is: \n");
    display(first);
    printf("\n");
   

    insertsort(first,index,1);

    printf("Linked list after insertion is : \n");
    display(first);


    return 0;
}