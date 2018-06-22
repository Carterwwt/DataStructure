#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;
typedef int  ElemType;
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
}BiTnode,*BiTree;


void queue_swap(queue<BiTree> &q1,queue<BiTree> &q2)
{
    while(!q2.empty())
    {
        BiTree tmp=q2.front();
        q2.pop();
        q1.push(tmp);
    }
}

bool searchBST(BiTree T,int key,BiTree f,BiTree &p)
{
    if (!T)
    {
        p = f;
        return false;
    }
    else if (key == T->data)
    {
        p = T;
        return true;
    }
    else if (key < T->data)
        return searchBST(T->lchild, key, T, p);
    else
        return searchBST(T->rchild, key, T, p);
}

bool insertBST(BiTree &T, int key)
{
    BiTree p, s;
    //因为search过程中有进行比较,所以search完T就指向该插入位置的父亲
    if (!searchBST(T, key, NULL, p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p)  T = s;//p是空的说明树是空的,则插入在根节点
        else if(key < p->data) p->lchild = s;
        else     p->rchild = s;
        return true;
    }
    else
        return false;
}

Status PrintElement(ElemType e)
{
    // 输出元素e的值
    printf("%d ",e);
    return OK;
}// PrintElement


Status PreOrderTraverse(BiTree T,Status(*Visit)(ElemType))
{
    // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
    if(T)
    {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild,Visit))
                if(PreOrderTraverse(T->rchild,Visit)) return OK;
        return ERROR;
    }
    else
        return OK;
} // PreOrderTraverse

Status InOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
    if(T){
        if(InOrderTraverse(T->lchild,Visit))
            if(Visit(T->data))
                if(InOrderTraverse(T->rchild,Visit)) return OK;
        return ERROR;
    }else return OK;
} // InOrderTraverse

Status InOrderTraverse_Stack(BiTree T,Status (*Visit)(ElemType))
{
    stack<BiTree> S;
    BiTree p=T;
    while(!S.empty()||p)
    {
        if(p)
        {
            S.push(p);
            p=p->lchild;
        }
        else
        {
            p=S.top();
            S.pop();
            if(!Visit(p->data)) return ERROR;
            p=p->rchild;
        }
    }
    return OK;
}

Status PostOrderTraverse(BiTree T,Status(*Visit)(ElemType))
{
    // 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
    if(T)
    {
        if(PostOrderTraverse(T->lchild,Visit))
            if(PostOrderTraverse(T->rchild,Visit))
                if(Visit(T->data)) return OK;
        return ERROR;
    }
    else return OK;
} // PostOrderTraverse

void Print_at_level(BiTree T)
{
    queue<BiTree> q1,q2;
    q1.push(T);
    while(!q1.empty())
    {
        while(!q1.empty())
        {
            BiTree tmp=q1.front();
            q1.pop();
            cout<<tmp->data<<" ";
            if(tmp->lchild)
                q2.push(tmp->lchild);
            if(tmp->rchild)
                q2.push(tmp->rchild);
        }
        queue_swap(q1,q2);

    }
    cout<<endl;
}

int height(BiTree T){
    if(T==NULL) return 0;
    int left=0,right=0;
    left=height(T->lchild);
    right=height(T->rchild);
    if(left>right) return left+1;
    return right+1;
}

int leaf(BiTree T){
    if(!T) return 0;
    if(T->lchild==NULL && T->rchild==NULL) return 1;
    return leaf(T->lchild)+leaf(T->rchild);
}

void BiTree_exchange(BiTree &T){
    if(T){
        BiTree_exchange(T->lchild);
        BiTree_exchange(T->rchild);
        BiTree tmp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = tmp;
    }
}


int main()
{
    int n,input;
    cin>>n;
    BiTree T=NULL,p=NULL,f=NULL;
    while(n--)
    {
        cin>>input;
        if(!insertBST(T,input)) break;
    }
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    n=2;
    while(n--)
    {
        int key;
        cin>>key;
        if(searchBST(T,key,f,p)) printf("1\n");
        else  printf("0\n");
    }
    int sert;
    cin>>sert;
    insertBST(T,sert);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse_Stack(T,PrintElement);//非递归中序
    printf("\n");
    Print_at_level(T);
    BiTree_exchange(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    BiTree_exchange(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    cout<<height(T)<<endl;
    cout<<leaf(T)<<endl;
    return 0;
}
