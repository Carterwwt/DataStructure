#include<stdio.h>
#include<cstdlib>
#define ERROR 0
#define OK 1
#define ElemType int

typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;


Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
  // 在带头结点的单链线性表L的第i个元素之前插入元素e
  LinkList p,s;
  p = L;
  int j = 0;
  while (p && j < i-1) {  // 寻找第i-1个结点
    p = p->next;
    ++j;
  }
  if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
  s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
  s->data = e;  s->next = p->next;      // 插入L中
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // 算法2.10
  // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // 寻找第i个结点，并令p指向其前趋
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
  q = p->next;
  p->next = q->next;           // 删除并释放结点
  e = q->data;
  free(q);
  return OK;
} // ListDelete_L

void createlist(LinkList &L, int n){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    int data;
    LinkList p,tail;
    for(int i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&data);
        p->data=data;
        if(L->next==NULL)   L->next=p;
        else  tail->next=p;
        tail=p;
        tail->next=NULL;
    }
}

void printlist(LinkList &L){
    LinkList p=L->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void linkreverse(LinkList &L){
    LinkList prev,p,after;
    p=L->next;
    L->next=NULL;
    prev=NULL;
    while(p){
        after=p->next;
        p->next=prev;
        //printf("prev data:%d  p data:%d  after data:%d  \n",prev->data,p->data,after->data);
        prev=p; p=after;
    }
    L->next=prev;
}

int main(){
    int n;
    LinkList L;
    scanf("%d",&n);
    createlist(L,n);
    printf("The List is:");
    printlist(L);
    linkreverse(L);
    printf("The turned List is:");
    printlist(L);
    return 0;
}
