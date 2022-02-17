#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *head, *tail;
int size = 0;
void insert_node(int insert)
{
    NODE *cell = (NODE*)malloc(sizeof(NODE));
    cell->data = insert;
    NODE *curr = head;
    if(head == NULL)
    {
        head = cell;
        tail = cell;
        size++;
        return;
    }else if(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = cell;
    tail = curr->next;
    size++;
}
void print_list()
{
    NODE *current;
    current = head;
    int count = 0;
    while(count != size)
    {
        printf("%d\n", current->data);
        current = current->next;
        count++;
    }
}
long sum_value(NODE *start){
    NODE *curr = start;
    long sum = 0;
    while(curr != NULL){
        sum = sum+curr->data;
        curr = curr->next;
    }
    return sum;
}
int main()
{
    insert_node(1);
    insert_node(2);
    insert_node(3);
    print_list();
    int x = sum_value(head);
    printf("%d",x);
    return 0;
}