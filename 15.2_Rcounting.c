// WAP to count the no of Nodes Recursively in a Linked list by inserting Nodes at left side.

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

int count(struct Node *p){

    if(p!=0){
        return count(p->next)+1;
    }
    return 0;
    }

    

int main(){
    int n,value;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Length is %d\n", count(first));
    return 0;
}