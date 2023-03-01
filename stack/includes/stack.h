#ifndef STACK_H
#define STACK_H

#include "data.h"
#include <stdio.h>

typedef struct node
{
	data_t data;
	struct node* prev;
	struct node* next;
}node_t;

typedef struct list
{
	node_t* head;
	node_t* tail;
	size_t size;
}stack_t;

typedef stack_t* Stack_t;

void put_stack(Stack_t stack);
void push(Stack_t stack, data_t data);
void pop(Stack_t stack);
void free_stack(Stack_t stack);
Stack_t new_stack(void);

#endif
