#ifndef LIST_H
#define LIST_H

#include "data.h"

typedef struct node
{
    data_t data;
    struct node* next;
}node_t;

typedef struct list
{
    node_t* point;
    node_t* curr;
    int size;
}list_t;

typedef list_t* List_t;

void put_list(List_t list);
void free_list(List_t list);
void move_curr(List_t list, int index);

int insert_data(List_t list, int index, data_t data);
int index_of_data(List_t list, data_t data);
int count_data(List_t list);

data_t delete_data(List_t list, int index);
data_t extract_data(List_t list, int index);

List_t new_list(void);

#endif
