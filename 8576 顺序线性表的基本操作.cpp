#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) return ERROR;
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	int i;
	if(L.length==0) printf("The List is empty!");  // 请填空
	else
	{
		ElemType *p=L.elem;
		printf("The List is: ");
		for(i=0;i<L.length;i++)
		    printf("%d ",*p++); // 请填空
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
// i的合法值为1≤i≤L.length +1
// 请补全代码
    if(i<1||i>L.length+1)  return ERROR;
    if(L.length>=L.listsize){
        ElemType *newbase=(ElemType *)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) return ERROR;
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    ElemType *q=&(L.elem[i-1]);//要插入的位置
    for(ElemType *p=&(L.elem[L.length-1]);p>=q;--p)
        *(p+1)=*p;
    *q=e;
    L.length+=1;
    return OK;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
// i的合法值为1≤i≤L.length
// 请补全代码
    if(i<1||i>L.length)  return ERROR;
    ElemType *p=&L.elem[i-1];//令P指向被删除元素
    e=*p;//e用于存放被删除的值
    ElemType *q=L.elem+L.length-1;//指向表尾元素
    for(p++;p<=q;p++)
        *(p-1)=*p;
    L.length-=1;
    return OK;
}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T))    // 判断顺序表是否创建成功
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					if(!ListInsert_Sq(T,i,x)) printf("Insert Error!\n"); // 判断i值是否合法，请填空
					else{
					    printf("The Element %d is Successfully Inserted!\n", x);
					}
					break;
			case 2: scanf("%d",&i);
                    int e;
					if(!ListDelete_Sq(T,i,e)) printf("Delete Error!\n"); // 判断i值是否合法，请填空
					else{
					     printf("The Element %d is Successfully Deleted!\n", e);
					}
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}
