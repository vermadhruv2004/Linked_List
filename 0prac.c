#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void create(int value, struct Node *last){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

}