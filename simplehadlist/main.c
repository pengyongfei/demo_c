#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    int arr[] ={1,21,0,50,70,23,11,55,77,99,11,21,33,41,4};
    list_t *list;
    list = list_create();
    if(list==NULL)
    {
        exit(1);

    }
    for(int i=0;i<sizeof(arr)/sizeof(*arr);i++)
    {
      //if(list_insert_at(list,0,&arr[i]))
       if(list_order_insert(list,&arr[i]))
       {
           exit(1);
       }
    }
   // int value = 50;
    list_display(list);
    int value ;
    //list_delete_at(list,&value);
    int err = list_delete(list,2,&value);
    if(err)
        exit(1);
    list_display(list);
    printf("value = %d\r\n",value);
    list_destroy(list);
    exit(0);
}
