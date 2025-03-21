// WAP to count the Nodes having even info in a linked list by inserting Node at right hand side.

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

int count(struct Node *p){

    int c=0;
    while(p!=NULL){
        if(p->data%2==0){
        c++;
        }
        p=p->next;
    }
    return c;
}

int main(){
    int n,value;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n",i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Even element in a list is %d\n", count(first));

    return 0;
}