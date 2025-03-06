//  WAP to check if a Linked List is sorted or not.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int sorted(struct Node *p){
    int x=INT_MIN;

    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

int main(){
    int n,value;
    printf("Enter the no of elements in LL\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }
    printf("Linked list is:\n");
    display(first);
    printf("\n");

    int temp=sorted(first);

    if(temp){
        printf("Linked list is sorted\n");
    }
    else{
        printf("Linked list is not sorted");
    }

    return 0;
}