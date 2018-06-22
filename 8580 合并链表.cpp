#include<stdio.h>
#include <cstdlib>
#include <cstdio>
#define ERROR 0
#define OK 1
#define ElemType int

typedef int Status;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void CreateList(LinkList &L,int i){
    LinkList tail,p;
    int n;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    tail=L;
    while(i--){
        scanf("%d",&n);
        p=(LinkList)malloc(sizeof(LNode));
        p->data=n;
        if(L->next==NULL)
            L->next=p;
        else{
            tail->next=p;
        }
        tail=p;
        tail->next=NULL;
    }
}

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
} // ListDelete_L\

void ListLoad(LinkList &L){
    LinkList p=L->next;
    if(!p)  printf("The list is empty!");
    else{
        while(p){
            printf("%d ",p->data);
            p=p->next;
        }
    }
    printf("\n");
}

void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc){
    LinkList pa=La->next,pb=Lb->next,pc;
    Lc=pc=La;
    while(pa&&pb){
        if(pa->data<pb->data){
            pc->next=pa; pc=pa; pa=pa->next;
        }
        else{
            pc->next=pb; pc=pb; pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
    free(Lb);
}

int main(){
    LinkList La,Lb,Lc;
    int i;
    scanf("%d",&i);
    CreateList(La,i);
    printf("List A:");
    ListLoad(La);
    scanf("%d",&i);
    CreateList(Lb,i);
    printf("List B:");
    ListLoad(Lb);
    MergeList(La,Lb,Lc);
    printf("List C:");
    ListLoad(Lc);
}
