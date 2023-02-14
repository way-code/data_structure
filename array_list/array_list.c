#include "array_list.h"

void init_list(List_t plist)
{
    plist->size = 0;
}

void show_list(List_t plist)
{
    size_t idx;

    for (idx = 0; idx < plist->size; idx++)
    {
        printf("[%4zd] : [%4d]\n", idx, plist->array[idx]);
    }
}

int add_data(List_t plist, data_t data)
{
    if (plist->size >= ARRAY_SIZE)
    {
        return (-1);
    }
    plist->array[plist->size] = data;
    plist->size++;
    return (plist->size);
}

int insert_data(List_t plist, data_t data, size_t index)
{
    size_t idx;

    if (plist->size >= ARRAY_SIZE || index >= ARRAY_SIZE ||
        index > plist->size)
    {
        return (-1);
    }
    for (idx = plist->size; idx > index; idx--)
    {
        plist->array[idx] = plist->array[idx - 1];
    }
    plist->array[index] = data;
    plist->size++;
    return (index);
}

size_t search_data(List_t plist, data_t data)
{
    size_t idx;

    for (idx = 0; idx < plist->size; idx++)
    {
        if (plist->array[idx] == data)
        {
            return (idx);
        }
    }
    return (-1);
}

size_t count_data(List_t plist)
{
    return (plist->size);
}

data_t show_data(List_t plist, size_t index)
{
    if (index <= 0 || index >= ARRAY_SIZE)
    {
        return (-1);
    }
    return (plist->array[index]);
}

data_t erase_data(List_t plist)
{
    data_t r_value;

    if (plist->size <= 0)
    {
        return (-1);
    }
    r_value = plist->array[plist->size];
    plist->size--;
    return (r_value);
}

data_t delete_data(List_t plist, size_t index)
{
    size_t idx;
    data_t r_value;

    if (plist->size <= 0 || index >= plist->size ||
        index == 0)
    {
        return (-1);
    }
    r_value = plist->array[index];
    for (idx = index; idx < plist->size; idx++)
    {
        plist->array[idx] = plist->array[idx + 1];
    }
    plist->size--;
    return (r_value);
}