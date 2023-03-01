#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void put_stack(Stack_t stack)
{
	node_t* point = stack->head->next;

	printf("[ ");
	while (point->next != NULL)
	{
		put_data(point->data);
		putchar(',');
		point = point->next;
	}
	put_data(point->data);
	printf(" ]\n");
}

void push(Stack_t stack, data_t data)
{
	node_t* new_node = (node_t*)malloc(sizeof(node_t));

	if (!new_node)
	{
		return ;
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	stack->tail->next = new_node;
	stack->tail = new_node;
	stack->size++;
}

void pop(Stack_t stack)
{
	node_t* d_node = stack->tail;

	if (d_node == stack->head)
	{
		return ;
	}
	stack->tail = stack->tail->prev;
	stack->size--;
	free(d_node);
}

void free_stack(Stack_t stack)
{
	node_t* d_node = stack->tail;

	while (d_node != stack->head)
	{
		stack->tail = d_node->prev;
		free(d_node);
		d_node = stack->tail;
	}
	free(stack->head);
	free(stack);
}

Stack_t new_stack(void)
{
	Stack_t new_stack = (Stack_t)malloc(sizeof(stack_t));

	if (new_stack)
	{
		new_stack->head = (node_t*)malloc(sizeof(node_t));
		if (!new_stack->head)
		{
			return (NULL);
		}
		new_stack->head->prev = NULL;
		new_stack->head->next = NULL;
		new_stack->tail = new_stack->head;
		new_stack->size = 0;
	}
	return (new_stack);
}
