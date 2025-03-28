// WAP to print min Node in a list using recursive function at left side.
// Method-2

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int min(struct Node *p){

    int minv=INT_MAX;
    int x=0;

    if(p==0){
        return minv;
    }

    x=min(p->next);

    return x<p->data ? x : p->data;
}

int main(){
    int n,value;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Min elements is %d\n", min(first));

    return 0;
}