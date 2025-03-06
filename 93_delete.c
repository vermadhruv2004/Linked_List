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

void delete(struct Node *p, int index, int x){

    if(first==NULL){
        printf("List is empty, can't delete the element\n");
        return;
    }

    struct Node *q=NULL;
    if(index==1){
        p=first;
        first=first->next;
        x=p->data;
        free(p);

        if(first){
            first->prev=NULL;
        }
    }

    else{
        for(int i=0;i<index-1 && p!=NULL; i++){
            q=p;
            p=p->next;
        }
    if(p){
        q->next=p->next;
        if(p->next){
            p->next->prev=q;
        }
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
