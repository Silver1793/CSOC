/*
 * stack.h
 *
 *  Created on: Feb 19, 2021
 *      Author: nikitaorbits
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include "status.h"

typedef void* MY_STACK;

MY_STACK stack_init_default();

void stack_destroy(MY_STACK* phMy_stack);

Status stack_push(MY_STACK hMy_stack, char c);

char stack_top(MY_STACK hMy_stack);

Boolean stack_empty(MY_STACK hMy_stack);

Status stack_pop(MY_STACK hMy_stack);



#endif /* STACK_H_ */
