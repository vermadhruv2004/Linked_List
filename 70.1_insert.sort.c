// Inserting elements in a sorted list at a sorted position by inserting multiple elements.

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

void insertsorted(struct Node *p,int index,int x){

    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    
    while(p->next!=NULL && p->next->data<x){
        p=p->next;
    }

    if(p==first){
        temp->next=first;
        first=temp;
    }
    
    else{
        if(p){
            temp->next=p->next;
            p->next=temp;
            if(last==p){
                last=temp;
            }
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
   

    insertsorted(first,index,5);

    printf("Linked list after insertion is : \n");
    display(first);


    return 0;
}