// Deleting an elements at a particular position in a existing Linked List userdefined code.

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

void delete(struct Node *p, int index){

    struct Node *temp;
    if(index==1){
        temp=first;
        first=first->next;
        free(temp);
        
        if(first==NULL){
            last=NULL;
        }
    }

    else{
        p=first;
        for(int i=0;i<index-2 && p!=NULL; i++){
            p=p->next;
        }

        temp=p->next;
        p->next=temp->next;

        if(temp==last){
            last=p;
        }
        free(temp);
    }
}

int main(){
    int n,value,index;
    printf("Enter the no of elements to be inserted\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("LL before deletion is: \n");
    display(first);
    printf("\n");

    printf("Enter the index for deletion an element\n");
    scanf("%d", &index);

    delete(first,index);

    printf("LL after deletion is: \n");
    display(first);

    return 0;

}