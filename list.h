#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    struct node *next;
    int value;
}node;

typedef struct list
{
    node *head;
    node *tail;
    int size;
}list;

node *create_node(int val);
list *create_list();
void list_add_front(list *a, int val);
void list_add_end(list *a, int val);
node *lookup(list *a, int key);
void print_list(list* a);
int list_size(list *a);
void list_clear(list *a);
void list_delete(list *a, int key);
void list_destroy(list **a);