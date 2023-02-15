#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "data.h"
# include <stdio.h>

typedef struct node
{
    data_t          data;
    struct node* next;
    struct node* prev;
}node_t;

typedef struct list
{
    node_t* head;
    node_t* tail;
    node_t* seek;
    size_t  size;
}list_t;

typedef list_t* List_t;

void    init_list(List_t list);
void    print_list(const List_t list);
void    print_data(const List_t list, const size_t index);
void    free_list(List_t list);
void    delete_list(List_t origin, const List_t to_del);
void    move_seek(List_t list, const size_t index);
int     add_data(List_t list, const data_t data);
int     insert_data(List_t list, const data_t data, const size_t index);
int     add_list(List_t origin, List_t to_add);
size_t  search_data(const List_t list, const data_t data);
size_t  search_list(const List_t origin, const List_t to_search);
size_t  count_data(const List_t list);
data_t  get_data(const List_t list, const size_t index);
data_t  erase_data(List_t list);
data_t  delete_data(List_t list, const size_t index);

#endif
