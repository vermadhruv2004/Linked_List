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
        last->next=first;
    }
    else{
        last->next=t;
        last=t;
        last->next=first;
    }
}

void display(struct Node *p){
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=first);
}

void delete(struct Node *p, int index, int x){

    if(first==NULL){
        printf("List is empty, can't delete the element\n");
        return;
    }
    struct Node *q=NULL;

    if(index==1){
        p=first;
        first=first->next;
        last->next=first;
        x=p->data;
        free(p);
    }
    else{
        for(int i=0;i<index-1; i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            free(p);
        }
    }
    
}

int main(){
    int n,value,x;
    printf("Enter the no of elements in a LL\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("LL before deletion is: \n");
    display(first);
    printf("\n");

    delete(first,1,x);

    printf("LL after deletion is: \n");
    display(first);
    

    return 0;
}