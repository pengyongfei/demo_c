#ifndef SQLIST_H_
#define SQLIST_H_
#define DATA_SIZE 1024
typedef  int datatype_t ;
typedef struct
{
    datatype_t data[DATA_SIZE];
    int last;
}sqlist_t;
sqlist_t* sqlist_create(void);

void sqlist_createl(sqlist_t **sq);

int sqlist_insert(sqlist_t *sq,int i,datatype_t *data);
int sqlist_delete(sqlist_t *sq,int i);
int sqlist_find(sqlist_t *sq,datatype_t *data);//查找指定数据
void sqlist_display(sqlist_t *sq);
int sqlist_isempty(sqlist_t *sq);//判断数据机构是否为空
int sqlist_setempty(sqlist_t *sq);//设置数据机构为空
int sqlist_getnum(sqlist_t *sq);//查看当前数据机构有多少数据
int sqlist_destroy(sqlist_t *sq);//销毁当前数据机构
int sqlist_union(sqlist_t *sq1,sqlist_t *sq2);//合并两个线性表









#endif
