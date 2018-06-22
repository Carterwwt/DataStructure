#include <iostream>
#include <cstdlib>

#define MAXN 100
using namespace std;
int dlta[MAXN];

typedef int KeyType;

typedef struct {
    KeyType key;
}RedType;

typedef struct{
    RedType r[MAXN+1];
    int length;
}SqList;

void PrintList(SqList L)
{
    for(int i=1;i<=L.length;i++) cout<<L.r[i].key<<" ";
    cout<<endl;
}

void keyswap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}

int Partition(SqList &L,int low,int high){
    L.r[0].key=L.r[low].key;
    int pivotkey=L.r[low].key;
    while(low<high){
        while(low<high&&L.r[high].key>=pivotkey) high--;
        L.r[low].key=L.r[high].key;
        while(low<high&&L.r[low].key<=pivotkey) low++;
        L.r[high].key=L.r[low].key;
    }
    L.r[low].key=L.r[0].key;
    PrintList(L);
    return low;
}

void Qsort(SqList &L,int low,int high){
    if(low<high){
        int pivotloc=Partition(L,low,high);
        Qsort(L,low,pivotloc-1);
        Qsort(L,pivotloc+1,high);
    }
}

void QuickSort(SqList &L){
    Qsort(L,1,L.length);
}

int main()
{
    SqList L;
    int n;
    cin>>n;
    L.length=n;
    for(int i=1;i<=n;i++)
    {
        cin>>L.r[i].key;
    }
    QuickSort(L);
    return 0;
}
