/*
 * main.c
 *
 *  Created on: Feb 19, 2021
 *      Author: nikitaorbits
 *      Program: String Balance Day8
 *      Finished: 02/24/2021
 *      Time Spent: 8 - 10 hours
 *      Purpose: This program uses the stack data structure to read in a string filled with '{' '}' '[' ']' '(' ')' and determines
 *      whether it is balanced based on if there is the same amount of closing symbols to the corresponding opening symbols
 */


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status check_test();
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int test;
	int i = 0;
	scanf("%d", &test);
	clear_keyboard_buffer();
	while(i < test)
	{
		if(check_test())
		{
			printf("Yes\n");
		}
		else
		{

			printf("No\n");
		}
		i++;
	}

	return 0;
}


Status check_test()
{
	MY_STACK hMy_stack;
	char c;
	int noc;
	hMy_stack = stack_init_default();
	if(hMy_stack == NULL)
	{
		printf("Failed to create stack object");
		exit(1);
	}
	noc = scanf("%c", &c);
	while(noc == 1 && c != '\n')
	{
		if(c == '{' || c == '[' || c == '(')
		{
			stack_push(hMy_stack, c);
		}
		else if(c == '}' || c == ']' || c ==')')
		{
			if(c == '}' && (stack_top(hMy_stack) != '{' || stack_empty(hMy_stack)))
			{
				clear_keyboard_buffer();
				stack_destroy(&hMy_stack);
				return FAILURE;
			}
			else if(c == ']' && (stack_top(hMy_stack) != '[' || stack_empty(hMy_stack)))
			{
				clear_keyboard_buffer();
				stack_destroy(&hMy_stack);
				return FAILURE;
			}
			else if(c == ')' && (stack_top(hMy_stack) != '(' || stack_empty(hMy_stack)))
			{
				clear_keyboard_buffer();
				stack_destroy(&hMy_stack);
				return FAILURE;
			}
			else
			{
				stack_pop(hMy_stack);
			}
		}

		noc = scanf("%c", &c);
	}
	if(stack_empty(hMy_stack) && c == '\n')
	{
		stack_destroy(&hMy_stack);
		return SUCCESS;
	}
	stack_destroy(&hMy_stack);
	return FAILURE;
}

void clear_keyboard_buffer()
{
	char c;
	int noc;
	noc = scanf("%c", &c);
	while(noc == 1 && c != '\n')
	{
		noc = scanf("%c", &c);
	}
}
