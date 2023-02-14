#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef unsigned int data_t;

typedef struct _node
{
    data_t data;
    struct _node* next;
}node_t;

typedef struct _list
{
    node_t* head;
    node_t* tail;
    node_t* seek;
    size_t size;
}list_t;

typedef list_t* List_t;

void init_list(List_t plist);
void remove_list(List_t plist);
void show_list(List_t plist);
int add_data(List_t plist, data_t data);
int insert_data(List_t plist, data_t data, size_t index);
size_t where_is_seek(List_t plist);
size_t search_data(List_t plist, data_t data);
size_t count_data(List_t plist);
data_t show_data(List_t plist, size_t index);
data_t erase_data(List_t plist);
data_t delete_data(List_t plist, size_t index);

#endif