/*
 * stack.c
 *
 *  Created on: Feb 19, 2021
 *      Author: nikitaorbits
 */
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct node Node;
struct node
{
	char data;
	Node* next;
};

struct stack
{
	Node* head;
};

typedef struct stack Stack;

MY_STACK stack_init_default()
{
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));
	if(pStack != NULL)
	{
		pStack->head = NULL;
	}
	return (MY_STACK)pStack;
}

void stack_destroy(MY_STACK* phMy_stack)
{
	Stack* pStack = (Stack*)* phMy_stack;
	Node* temp;
	while(pStack->head != NULL)
	{
		temp = pStack->head;
		pStack->head = pStack->head->next;
		free(temp);
	}
	free(pStack);
	*phMy_stack = NULL;
}

Boolean stack_empty(MY_STACK hMy_stack)
{
	Stack* pStack = (Stack*) hMy_stack;
	if(pStack->head == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

Status stack_push(MY_STACK hMy_stack, char c)
{
	Stack* pStack = (MY_STACK)malloc(sizeof(MY_STACK));
	/*Stack**/ pStack = (Stack*) hMy_stack;
	Node* temp = (Node*) malloc(sizeof(Node));
	if(temp == NULL)
	{
		return FAILURE;
	}
	temp->data = (char)malloc(sizeof(char)*2);
	temp->data = c;
	pStack->head = temp;
	return SUCCESS;
}

Status stack_pop(MY_STACK hMy_stack)
{
	Stack* pStack = (Stack*) hMy_stack;
	if(pStack->head == NULL)
	{
		return FAILURE;
	}
	pStack->head = pStack->head->next;
	return SUCCESS;
}

char stack_top(MY_STACK hMy_stack)
{
	Stack* pStack = (Stack*) hMy_stack;
	if(pStack->head == NULL)
	{
		return '\0';
	}
	return pStack->head->data;
}
