#include "linked_list.h"
#include <stdlib.h>

void init_list(List_t list)
{
    list->head = NULL;
    list->tail = NULL;
    list->seek = NULL;
    list->size = 0;
}

void print_list(const List_t list)
{
    list->seek = list->head;
    printf("[ ");
    while (list->seek)
    {
        put_data(list->seek->data);
        if (list->seek->next)
        {
            putchar(',');
        }
        list->seek = list->seek->next;
    }
    printf(" ]");
    putchar('\n');
}

void print_data(const List_t list, const size_t index)
{
    size_t idx;

    if (!list->head || index > list->size)
    {
        return;
    }
    list->seek = list->head;
    for (idx = 0; idx < index; idx++)
    {
        list->seek = list->seek->next;
    }
    printf("[%zd] : ", index);
    put_data(list->seek->data);
    putchar('\n');
}

void free_list(List_t list)
{
    node_t* to_del = list->head;

    if (!to_del)
    {
        return;
    }
    list->head = list->head->next;
    if (!list->head)
    {
        free(to_del);
        return;
    }
    while (list->head)
    {
        free(to_del);
        list->head = list->head->next;
    }
}

void delete_list(List_t origin, const List_t to_del)
{
    node_t* point;
    size_t index;
    size_t idx;

    if (!origin->head || !to_del->head)
    {
        return;
    }
    index = search_list(origin, to_del);
    if (index == -1)
    {
        return;
    }
    move_seek(origin, index - 1);
    for (idx = index; idx < origin->size; idx++)
    {
        point = origin->seek;
        origin->seek = origin->seek->next;
        point->next->prev = point->prev;
        point->prev->next = point->next;
        free(point);
    }
}

void move_seek(List_t list, const size_t index)
{
    size_t idx;

    list->seek = list->head;
    for (idx = 0; idx < index; idx++)
    {
        list->seek = list->seek->next;
    }
}

int add_data(List_t list, const data_t data)
{
    return (insert_data(list, data, count_data(list)));
}

int insert_data(List_t list, const data_t data, const size_t index)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    size_t idx;

    if (!new_node || index > count_data(list))
    {
        return (-1);
    }
    move_seek(list, index);
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (!list->seek)
    {
        list->head = new_node;
        list->tail = list->head;
    }
    else if (!list->seek->prev && list->seek->next)
    {
        list->head = new_node;
        list->head->next = list->seek;
        list->seek->prev = list->head;
    }
    else if (list->seek->prev && !list->seek->next)
    {
        list->tail = new_node;
        list->tail->prev = list->seek;
        list->seek->next = list->tail;
    }
    else
    {
        new_node->next = list->seek->next;
        list->seek->next->prev = new_node;
        new_node->prev = list->seek;
        list->seek->next = new_node;
    }
    list->size++;
    return (list->size);
}

int add_list(List_t origin, List_t to_add)
{
    if (!origin->head && !to_add->head)
    {
        return (-1);
    }
    origin->tail->next = to_add->head;
    to_add->head->prev = origin->tail;
    return (origin->size + to_add->size);
}

size_t search_data(const List_t list, const data_t data)
{
    size_t idx = 0;

    list->seek = list->head;
    while (list->seek)
    {
        if (list->seek->data == data)
        {
            return (idx);
        }
        list->seek = list->seek->next;
        idx++;
    }
    return (-1);
}

size_t search_list(const List_t origin, const List_t to_search)
{
    size_t idx;

    if (!origin->head || !to_search->head)
    {
        return (-1);
    }
    idx = search_data(origin, to_search->head->data);
    move_seek(origin, idx);
    move_seek(to_search, 0);
    while (origin->seek)
    {
        if (origin->seek->data != to_search->seek->data)
        {
            return (-1);
        }
        origin->seek = origin->seek->next;
        to_search->seek = to_search->seek->next;
    }
    return (idx);
}

size_t count_data(const List_t list)
{
    return (list->size);
}

data_t get_data(const List_t list, const size_t index)
{
    if (!list->head)
    {
        return (-1);
    }
    move_seek(list, index);
    return (list->seek->data);
}

data_t erase_data(List_t list)
{
    data_t r_value;

    if (!list->head)
    {
        return (-1);
    }
    return (delete_data(list, count_data(list) - 1));
}

data_t delete_data(List_t list, const size_t index)
{
    data_t r_value;
    size_t idx;

    if (!list->head || index >= count_data(list))
    {
        return (-1);
    }
    move_seek(list, index);
    r_value = list->seek->data;
    if (!list->seek->prev)
    {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    else if (!list->seek->next)
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    else
    {
        list->seek->prev->next = list->seek->next;
        list->seek->next->prev = list->seek->prev;
    }
    free(list->seek);
    list->size--;
    return (r_value);
}
