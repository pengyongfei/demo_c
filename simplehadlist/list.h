#ifndef LIST_H_
#define LIST_H_


typedef struct node_st
{
    int data;
    struct node_st *next;

}list_t;
list_t * list_create();
int list_insert_at(list_t *list,int i,int *data);
int list_order_insert(list_t *list,int *data);
int list_delete(list_t *list,int i,int *data);
int list_delete_at(list_t *list,int *data);
int list_isempty(list_t *list);
void list_display(list_t *list);

void list_destroy(list_t *list);



#endif

