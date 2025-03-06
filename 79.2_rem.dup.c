// WAP to remove duplicate element in a Sorted Linked List.

#include <stdio.h>
#include <stdlib.h>

struct Node {
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

void removedup(struct Node *p){
    struct Node *q=NULL;

    while(q!=NULL && q->next!=NULL){     // Ensure p and p->next are not NULL
        if(p->data==q->data){
           q->next=p->next;
           free(p);
           p=q->next;
        }
        else{
            q=p;
            p=p->next;
        }
    }
}

int main(){
    int n,value;
    printf("Enter the no of elements in a LL\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }
    
    printf("Linked list before remove duplicate elements is: \n");
    display(first);
    printf("\n");

    removedup(first);

    printf("Linked list after remove of duplicate elements is :\n");
    display(first);
    printf("\n");

    return 0;
}