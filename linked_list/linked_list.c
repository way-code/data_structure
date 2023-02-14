#include "linked_list.h"
#include <stdlib.h>

void init_list(List_t plist)
{
    plist->head = NULL;
    plist->tail = plist->head;
    plist->seek = plist->head;
    plist->size = 0;
}

void remove_list(List_t plist)
{
    plist->seek = plist->head;
    while (plist->head)
    {
        plist->head = plist->head->next;
        free(plist->seek);
        plist->seek = plist->head;
    }
}

void show_list(List_t plist)
{
    size_t idx = 0;

    plist->seek = plist->head;
    while (plist->seek)
    {
        printf("[%4zd] : [%4d]\n", idx, plist->seek->data);
        idx++;
        plist->seek = plist->seek->next;
    }
}

int add_data(List_t plist, data_t data)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    if (!new_node)
    {
        return (-1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (plist->head == NULL)
    {
        plist->head = new_node;
        plist->seek = plist->head;
    }
    else
    {
        plist->seek->next = new_node;
        plist->seek = plist->seek->next;
    }
    plist->tail = plist->seek;
    plist->size++;
    return (plist->size);
}

int insert_data(List_t plist, data_t data, size_t index)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    size_t idx;

    if (!new_node || index > plist->size)
    {
        return (-1);
    }
    plist->seek = plist->head;
    for (idx = 0; idx < index; idx++)
    {
        plist->seek = plist->seek->next;
    }
    new_node->data = data;
    new_node->next = plist->seek->next;
    plist->seek->next = new_node;
    plist->size++;
    return (plist->size);
}

size_t where_is_seek(List_t plist)
{
    node_t* node = plist->head;
    size_t idx = 0;

    while (node != plist->seek)
    {
        node = node->next;
        idx++;
    }
    return (idx);
}

size_t search_data(List_t plist, data_t data)
{
    size_t idx;

    plist->seek = plist->head;
    for (idx = 0; idx < plist->size; idx++)
    {
        if (plist->seek->data == data)
        {
            return (idx);
        }
        plist->seek = plist->seek->next;
    }
    return (-1);
}

size_t count_data(List_t plist)
{
    return (plist->size);
}

data_t show_data(List_t plist, size_t index)
{
    size_t idx;

    plist->seek = plist->head;
    if (index > plist->size)
    {
        return (-1);
    }
    for (idx = 0; idx < index; idx++)
    {
        plist->seek = plist->seek->next;
    }
    return (plist->seek->data);
}

data_t erase_data(List_t plist)
{
    if (!plist->tail)
    {
        return (-1);
    }
    return (delete_data(plist, plist->size - 1));
}

data_t delete_data(List_t plist, size_t index)
{
    node_t* d_node;
    data_t r_value;
    size_t idx;

    if (!plist->head || index > plist->size)
    {
        return (-1);
    }
    plist->seek = plist->head;
    for (idx = 0; idx < index - 1; idx++)
    {
        plist->seek = plist->seek->next;
    }
    d_node = plist->seek->next;
    plist->seek->next = d_node->next;
    r_value = d_node->data;
    free(d_node);
    plist->size--;
    return (r_value);
}