#include <stdio.h>
#include <stdlib.h>
#include "list.h"


list_t * list_create()
{
  //  list_t *list = malloc(sizeof())
    list_t *list ;
    list = malloc(sizeof(list));
    list->next = NULL;
    return list;
}
int list_insert_at(list_t *list,int i,int *data)
{
    int j = 0;
    list_t *node = list;
    list_t *newnode;//创建的新节点
    if(i>0)
        return -1;
    while(j<i && node !=NULL)//此处循环条件不成立
    {
        printf("j = %d\r\n",j);
        node = node->next;
        j++;
        printf("j=%d\r\n",j);
    }
    //printf("j=%d\r\n",j);
    if(node)//if(node != NULL)//node 不等于NULL
    {
        newnode = malloc(sizeof(*newnode));
        if(newnode==NULL)
            return -2;
        newnode->data = *data;//把增加的值赋值给数据点进行存储
        newnode->next = node->next;//上一个节点连接到新节点
        node->next = newnode;//新节点连接到下一个节点
        return 0;
    }
    else
        return -3;
}
int list_order_insert(list_t *list,int *data)
{
    list_t *p = list,*q;
    while(p->next && p->next->data <*data)//p指向下一个节点的数据小于*data 此处的循环是用于排序使用
        p = p->next;//p向下进行移动
    q = malloc(sizeof(*q));
    if(q==NULL)
        return -1;
    q->data = *data;//在q位置进行插入 *data
    q->next = p->next;//链接节点
    p->next = q;//当前节点连接下一个节点
    return 0;
}
int list_delete(list_t *list,int i,int *data)
{
   int j = 0;
    list_t *p = list,*q;
    *data = -1;
    if(i<0)
        return -1;
    while(j<i && p)
    {
        p = p->next;
        j++;
    }
    if(p)
    {
        q = malloc(sizeof(*q));
        q  = p->next;//当前节点使用q进行替换
        p->next = q->next;//上一个节点连接下一个节点，移除当前节点
        *data = q->data;//使用形参带回当前数据
        free(q);
        q = NULL;
        return 0;
    }
    else
        return -2;

}
int list_delete_at(list_t *list,int *data)
{
    list_t *p = list,*q;
    while(p->next && p->next->data != *data)
        p = p->next;
    if(p->next ==NULL)
        return -1;
    else
    {
        q = p->next;//当前节点使用q进行替换
        p->next = q->next;//上一个节点连接下一个节点，与当前节点断开连接
        free(q);
    }  
    return 0;
}
int list_isempty(list_t *list)
{
    if(list->next ==NULL)
        return 0;
    return 1;
}


void list_destroy(list_t *list)
{
    list_t *node, *newnext;
    for(node = list->next;node!=NULL; node = newnext )
    {
        newnext = node->next;
        free(newnext);
    }
    free(list);

   return;
}
void list_display(list_t *list)
{
    list_t *node = list->next;
    if(list_isempty(list)==0)
        return ;
    while(node !=NULL)
    {
        printf("%d, ",node->data);
        node = node->next;

    }
    printf("\r\n");
    return ;
}



