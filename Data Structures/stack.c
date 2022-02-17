#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define false 0
# define true 1
typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;
int size = 0;
void push(int insert)
{
    NODE *cell = (NODE*)malloc(sizeof(NODE));
    cell->data = (int)malloc(sizeof(int));
    cell->data = insert;

    NODE *temp = (NODE*)malloc(sizeof(NODE));
    if(size == 0)
    {
        head = cell;
        size++;
    }
    else if(size > 0)
    {
        temp = cell;
        temp->next = head;
        head = temp;
        size++;
    }
}
bool search(int x)
{
    NODE *current = head;
    while(current->next!=NULL)
    {
        if(current->data == x)
        {
            return true;
        }
    }
    return false;
}
void push2(int insert)
{
    NODE *cell = (NODE*)malloc(sizeof(NODE));
    cell->data = (int)malloc(sizeof(int));
    cell->data = insert;

    NODE *temp = (NODE*)malloc(sizeof(NODE));
    if(size == 0)
    {
        head = cell;
        size++;
    }
    else
    {
        temp = head;
        tail = cell;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = tail;
        size++;
    }
}
void pop()
{
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    if(size == 0)
    {
        head = NULL;
        printf("stack is empty");
        return;
    }
    else
    {
        temp=head->next;
        head=NULL;
        head = temp;
        size--;
    }
}
void pop2()
{
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    if(size == 0)
    {
        head = NULL;
        printf("stack is empty");
        return;
    }
    else
    {
        temp=head;
        /*head=NULL;
        head = temp;*/
        tail = NULL;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        tail = temp;
        size--;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    //search(1);
    //pop2();
    //pop2();
    for(int i=0; i < size; i++)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    return 0;
}