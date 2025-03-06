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

int count(struct Node *p){
    int c=0;
    while(p!=0){
        c++;
        p=p->next;
    }
    return c;
}

void insert(struct Node *p,int index, int x){
    
    if(index<0 && index>count(p)){
        printf("Invalid Index\n");
        return;
    }

    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;

    if(index==1){
        temp->next=first;
        temp->prev=NULL;
        first->prev=temp;
        first=temp;
    }
    else{
        p=first;
        for(int i=0;i<index-1 && p!=NULL; i++){
            p=p->next;
        }

        if(p!=NULL){
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
    int n,value;
    printf("Enter the no of element in a LL\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("LL before insertion is: \n");
    display(first);
    printf("\n");

    insert(first,5,10);

    printf("LL after insertion is: \n");
    display(first);

    return 0;
}