#ifndef	QUEUE_H
#define QUEUE_H

#include "data.h"
#include <stdio.h>

typedef struct node
{
	data_t data;
	struct node* prev;
	struct node* next;
}node_t;

typedef struct queue
{
	node_t* head;
	node_t* tail;
	size_t size;
}queue_t;

typedef queue_t* Queue_t;

void put_queue(Queue_t queue);
void add_data(Queue_t queue, data_t data);
void delete_data(Queue_t queue);
void free_queue(Queue_t queue);
Queue_t new_queue(void);

#endif
