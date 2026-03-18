#include "list.h"

node *create_node(int val)
{
    node *a = malloc(sizeof(node));

    if (a == NULL)
        return NULL;

    a->value = val;
    a->next = NULL;

    return a;
}

void print_list(list *a)
{
    node *temp = a->head;

    while (temp != NULL)
    {
        printf((temp->next != NULL) ? "%d --> " : "%d\n", temp->value);
        temp = temp->next;
    }
}

int list_size(list *a)
{
    if (a == NULL)
        return 0;

    return a->size;
}

list *create_list()
{
    list *a = malloc(sizeof(list));
    if (a == NULL)
        return NULL;

    a->head = a->tail = NULL;
    a->size = 0;
    return a;
}

void list_add_front(list *a, int val)
{
    if (a == NULL)
        return;

    node *temp = create_node(val);
    if (temp == NULL)
        return;

    temp->next = a->head;
    a->head = temp;

    if (a->tail == NULL)
        a->tail = temp;

    a->size++;
}

void list_add_end(list *a, int val)
{
    if (a == NULL)
        return;

    node *temp = create_node(val);
    if (temp == NULL)
        return;

    if (a->tail == NULL)
        a->head = a->tail = temp;

    else
    {
        a->tail->next = temp;
        a->tail = temp;
    }

    a->size++;
}

node *lookup(list *a, int key)
{
    if (a == NULL)
        return NULL;

    node *temp = a->head;
    while (temp != NULL)
    {
        if (temp->value == key)
            return temp;

        temp = temp->next;
    }
    return NULL;
}

void list_delete(list *a, int key)
{
    if (a == NULL)
        return;
    node *temp = a->head;
    node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            if (prev == NULL) {
                a->head = temp->next;
                if (a->head == NULL)
                    a->tail = NULL;
            }

            else {
                prev->next = temp->next;
                if (temp == a->tail)
                    a->tail = prev;
            }

            free(temp);
            a->size--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void list_clear(list *a)
{
    if (a->head == NULL)
        return;
    node *temp = a->head;
    node *prev = NULL;

    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        free(prev);
    }

    a->head = NULL;
    a->tail = NULL;
    a->size = 0;
}

void list_destroy(list **a)
{
    if (*a == NULL)
        return;

    list_clear(*a);
    free(*a);
    *a = NULL;
}