#include "list.h"

int main(void)
{
    list *a = create_list();

    for (int i = 0; i < 50; i++)
    {
        list_add_front(a, i);
    }

    print_list(a);
    printf("%d\n", list_size(a));

    list_delete(a, 2);
    list_delete(a, 5);
    print_list(a);

    printf("%d\n", list_size(a));

    list_destroy(&a);
    free(a);

    return 0;
}