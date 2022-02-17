#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include <string.h>

typedef struct node{
    int A[20];
    struct node *left;
    struct node *right;
}NODE;
void copy_to_right(NODE *p){
    if((p!=NULL)&& (p->right != NULL)){
        memcpy(p->right->A, p->A,40);
    }
}
int main()
{
    test();
}