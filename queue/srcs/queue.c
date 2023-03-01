#include "queue.h"
#include <stdlib.h>

void put_queue(Queue_t queue)
{
	node_t* point = queue->head->next;

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

void add_data(Queue_t queue, data_t data)
{
	node_t* new_node = (node_t*)malloc(sizeof(node_t));

	if (!new_node)
	{
		return ;
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = queue->tail;
	queue->tail->next = new_node;
	queue->tail = new_node;
	queue->size++;
}

void delete_data(Queue_t queue)
{
	node_t* d_node = queue->head->next;

	if (d_node == NULL)
	{
		return ;
	}
	queue->head->next = d_node->next;
	d_node->next->prev = queue->head;
	free(d_node);
}

void free_queue(Queue_t queue)
{
	node_t* d_node = queue->head->next;

	while (d_node != NULL)
	{
		queue->head->next = d_node->next;
		free(d_node);
		d_node = queue->head->next;
	}
	free(queue->head);
	free(queue);
}

Queue_t new_queue(void)
{
	Queue_t new_q = (Queue_t)malloc(sizeof(queue_t));

	if (new_q)
	{
		new_q->head = (node_t*)malloc(sizeof(node_t));
		if (!new_q->head)
		{
			return (NULL);
		}
		new_q->head->next = NULL;
		new_q->head->prev = NULL;
		new_q->tail = new_q->head;
		new_q->size = 0;
	}
	return (new_q);
}
