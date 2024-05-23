#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"



int main(void)
{

    int err ;
    datatype_t  arr[] = {0,1,2,3,4,5,6,7,8,9};
    datatype_t  arr1[] = {12,1,5,17,18,20,9,25};
 //   sqlist_t *list =NULL ;
    sqlist_t *list = sqlist_create();
    sqlist_t *list1 = sqlist_create();
    if(list==NULL)
    {
        printf("数据初始化失败\r\n");
        exit(1);
    }
    if(list1==NULL)
    {
        printf("数据初始化失败\r\n");
        exit(1);
    }
    
    //printf("打印位置信息: %d \r\n",sqlist_getnum(list));
    //printf("当前数组的空间大小为:%ld\r\n",sizeof(arr)/sizeof(*arr));
    for(int i=0;i<sizeof(arr)/sizeof(*arr);i++)//计算数据的大写:sizeof(arr)/sizeof(arr*)
    {

      sqlist_insert(list,0,&arr[i]);

   /* if((err = sqlist_insert(list,0,&arr[i]))!=0)
        {
            if(err==-1)
            {
                printf("内存已经装满\r\n");
            }
            else if(err ==-2)
            {
                printf("存放位置出错\r\n");
            }
            else
            printf("出错\r\n");
            exit(1);//1:表示非正常结束 0：表示正常结束
        }*/
    }
   // printf("======================\r\n");
    for(int i=0;i<sizeof(arr1)/sizeof(*arr1);i++)
    {
           sqlist_insert(list1,0,&arr1[i]); 
    }
    sqlist_display(list);
    sqlist_display(list1);
    sqlist_union(list,list1);
    sqlist_display(list);
    //printf("^:删除后有%d个数字\r\n",sqlist_getnum(list));
    sqlist_destroy(list);
    sqlist_destroy(list1);


}


