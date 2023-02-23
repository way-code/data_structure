#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void put_list(List_t list)
{
    list->curr = list->head->next;
    printf("[ ");
    while (list->curr->next != list->tail)
    {
        put_data(list->curr->data);
        list->curr = list->curr->next;
        putchar(',');
    }
    put_data(list->curr->data);
    printf(" ]\n");
}

void free_list(List_t list)
{
    while (list->head->next != list->tail)
    {
        list->curr = list->head->next;
        list->head->next = list->curr->next;
        free(list->curr);
    }
}

void move_curr(List_t list, int index)
{
    int i;

    list->curr = list->head;
    for (i = 0; i <= index; i++)
    {
        list->curr = list->curr->next;
    }
}

int insert_data(List_t list, int index, data_t data)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    if (!new_node || index > list->size)
    {
        return (-1);
    }
    new_node->data = data;
    move_curr(list, index - 1);
    new_node->next = list->curr->next;
    list->curr->next = new_node;
    list->size++;
    return (index);
}

int index_of_data(List_t list, data_t data)
{
    int idx;

    list->curr = list->head->next;
    for (idx = 0; idx < list->size; idx++)
    {
        if (list->curr->data == data)
        {
            return (idx);
        }
        list->curr = list->curr->next;
    }
    return (-1);
}

data_t delete_data(List_t list, int index)
{
    node_t* d_node;
    data_t d_data;

    if (list->head->next == list->tail || index >= list->size)
    {
        return (-1);
    }
    move_curr(list, index - 1);
    d_node = list->curr->next;
    d_data = d_node->data;
    list->curr->next = d_node->next;
    free(d_node);
    list->size--;
    return (d_data);
}

data_t extract_data(List_t list, int index)
{
    if (index >= list->size)
    {
        return (-1);
    }
    move_curr(list, index);
    return (list->curr->data);
}

List_t new_list(void)
{
    List_t list = (List_t)malloc(sizeof(list_t));

    if (list)
    {
        list->head = (node_t*)malloc(sizeof(node_t));
        list->tail = (node_t*)malloc(sizeof(node_t));
        if (!list->head || !list->tail)
        {
            return (NULL);
        }
        list->head->data = 0;
        list->head->next = list->tail;
        list->tail->data = 0;
        list->tail->next = NULL;
        list->curr = NULL;
        list->size = 0;
    }
    return (list);
}