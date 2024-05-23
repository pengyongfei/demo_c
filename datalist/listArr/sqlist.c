#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"
sqlist_t* sqlist_create(void)
{
    sqlist_t *sq ;
    sq = (sqlist_t*)malloc(sizeof(sq));
    if(sq ==NULL)
        return NULL;
    sq->last = -1;
    return sq;
}

void sqlist_createl(sqlist_t **sq)
{
    *sq = malloc(sizeof(**sq));
    if(*sq==NULL)
        return ;
    (*sq)->last = -1;
}
int sqlist_insert(sqlist_t *sq,int i,datatype_t *data)
{
    if(sq->last==DATA_SIZE-1)
        return -1;
    if(i<0||i>sq->last+1)
        return -2;
    for(int j = sq->last;i<=j;j--)
        sq->data[j+1] = sq->data[j];
    sq->data[i] = *data;
    sq->last++;
    return 0;
}
int sqlist_delete(sqlist_t *sq,int i)
{
   if(i<0 || i>sq->last)
        return -1;
    for(int j = i+1;j<=sq->last;j++)
        sq->data[j-1] = sq->data[j];
    sq->last --;
    return 0;
}
int sqlist_find(sqlist_t *sq,datatype_t *data)//查找指定数据
{
    int indx = 0;
    if(sqlist_isempty(sq)==0)
        return indx = -1;
    for(int i=0;i<sq->last;i++)
        if(sq->data[i]== *data)
            return i;
    return  indx = -2;
}
int sqlist_isempty(sqlist_t *sq)//判断数据机构是否为空
{
    if(sq->last == -1)//判断条件是否成立，成立返回0，否则返回-1；
        return 0;
    return -1;
}
int sqlist_setempty(sqlist_t *sq)//设置数据机构为空
{
    sq->last = -1;
    return 0;
}
int sqlist_getnum(sqlist_t *sq)//查看当前数据机构有多少数据
{
    return (sq->last);
    //return (sq->last +1);
}
int sqlist_destroy(sqlist_t *sq)//销毁当前数据机构
{
    printf("程序即将结束\r\n");
    free(sq);
    printf("程序结束\r\n");
    return 0;
}
int sqlist_union(sqlist_t *sq1,sqlist_t *sq2)//合并两个线性表
{
    for(int i=0;i<sq2->last;i++)
    {
        if(sqlist_find(sq1,&sq2->data[i])<0)
        {
            sqlist_insert(sq1,0,&sq2->data[i]);
        }
    }
}
void sqlist_display(sqlist_t *sq)
{
   if(sq->last==-1)
   {
       return ;
   }
   for(int i=0;i<sq->last;i++)
   {
       printf("%d \t",sq->data[i]);

   }
   printf("\r\n");
}

