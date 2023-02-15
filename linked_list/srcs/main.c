#include "linked_list.h"

int main(void)
{
    list_t list;
    data_t data;
    size_t idx;

    init_list(&list);
    for (idx = 0; idx < 10; idx++)
    {
        add_data(&list, idx);
    }
    print_list(&list);

    erase_data(&list);
    erase_data(&list);
    print_list(&list);

    delete_data(&list, 4);
    insert_data(&list, 100, 4);
    print_list(&list);

    for (idx = 0; idx < count_data(&list); idx++)
    {
        data = get_data(&list, idx);
        if (data % 2 == 0)
        {
            delete_data(&list, idx);
        }
    }
    print_list(&list);
    
    add_data(&list, 7);
    add_data(&list, 9);
    print_list(&list);

    free_list(&list);
    return 0;
}
