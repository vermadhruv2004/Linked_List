//  WAP to print max elements in a linked list using recursive function by inserting Node in a left side.


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

int max(struct Node *p){

    int maxval=INT_MIN;
    int x=0;

    if(p==0){
        return maxval;
    }

    else{
        x=max(p->next);

        if(x>p->data){
            return x;
        }

        else{
            return p->data;
        }    
    }
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

    printf("Max element is %d\n", max(first));

    return 0;
}