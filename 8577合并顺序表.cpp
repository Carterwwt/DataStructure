#include<stdio.h>
//#include <stdlib.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{  // 算法2.3
  // 构造一个空的线性表L。
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return ERROR;        // 存储分配失败
  L.length = 0;                  // 空表长度为0
  L.listsize = LIST_INIT_SIZE;   // 初始存储容量
  return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // 算法2.4
  // 在顺序线性表L的第i个元素之前插入新的元素e，
  // i的合法值为1≤i≤ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // i值不合法
  if (L.length >= L.listsize) {   // 当前存储空间已满，增加容量
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // 存储分配失败
    L.elem = newbase;             // 新基址
    L.listsize += LISTINCREMENT;  // 增加存储容量
  }
  ElemType *q = &(L.elem[i-1]);   // q为插入位置
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // 插入位置及之后的元素右移
  *q = e;       // 插入e
  ++L.length;   // 表长增1
  return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // 算法2.5
  // 在顺序线性表L中删除第i个元素，并用e返回其值。
  // i的合法值为1≤i≤ListLength_Sq(L)。
  ElemType *p, *q;
  if (i<1 || i>L.length) return ERROR;  // i值不合法
  p = &(L.elem[i-1]);                   // p为被删除元素的位置
  e = *p;                               // 被删除元素的值赋给e
  q = L.elem+L.length-1;                // 表尾元素的位置
  for (++p; p<=q; ++p) *(p-1) = *p;     // 被删除元素之后的元素左移
  --L.length;                           // 表长减1
  return OK;
} // ListDelete_Sq

Status Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
    int i;
    if(L.length==0) printf("The List is empty!");  // 请填空
    else
    {
        ElemType *p=L.elem;
        for(i=0;i<L.length;i++)
            printf("%d ",*p++); // 请填空
    }
    printf("\n");
    return OK;
}

Status MergeList(SqList La,SqList Lb,SqList &Lc)
{
    ElemType *pa=La.elem,*pb=Lb.elem;
    Lc.listsize=Lc.length=La.length+Lb.length;
    ElemType *pc=Lc.elem=(ElemType *)malloc(Lc.listsize* sizeof(ElemType));
    if(!Lc.elem) return ERROR;
    ElemType *La_last=La.elem+La.length-1,*Lb_last=Lb.elem+Lb.length-1;
    while(pa<=La_last&&pb<=Lb_last)
    {
        if(*pa <= *pb)  *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while(pa <= La_last) *pc++ = *pa++;
    while(pb <= Lb_last) *pc++ = *pb++;
}

Status main()
{
    int i,k;
    i=k=0;
    SqList La,Lb,Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);
    int e;
    scanf("%d",&i);
    while(i--)
    {
        scanf("%d",&e);
        if(!ListInsert_Sq(La,++k,e))
            return -1;
    }
    k=0;
    scanf("%d",&i);
    while(i--)
    {
        scanf("%d",&e);
        if(!ListInsert_Sq(Lb,++k,e))
            return -1;
    }
    if(!MergeList(La,Lb,Lc)) return -1;
    printf("List A:");Load_Sq(La);
    printf("List B:");Load_Sq(Lb);
    printf("List C:");Load_Sq(Lc);
    return 0;
}
