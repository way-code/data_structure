#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#define ARRAY_SIZE 1024

typedef unsigned int data_t;

typedef struct
{
    data_t array[ARRAY_SIZE];
    size_t size;
} list_t;

typedef list_t* List_t;

void init_list(List_t plist);
void show_list(List_t plist);
int add_data(List_t plist, data_t data);
int insert_data(List_t plist, data_t data, size_t index);
size_t search_data(List_t plist, data_t data);
size_t count_data(List_t plist);
data_t show_data(List_t plist, size_t index);
data_t erase_data(List_t plist);
data_t delete_data(List_t plist, size_t index);

#endif