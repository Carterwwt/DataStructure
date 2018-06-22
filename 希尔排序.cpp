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

void ShellInsert(SqList &L,int dk){
    int j,i;
    for(i=dk+1;i<=L.length;i++){
        if(L.r[i].key<L.r[i-dk].key){
            L.r[0].key=L.r[i].key;
            for(j=i-dk;j>0&&L.r[0].key<L.r[j].key;j-=dk)
                L.r[j+dk].key=L.r[j].key;
            L.r[j+dk].key=L.r[0].key;
        }
    }
}

void ShellSort(SqList &L,int dlta[],int t){
    for(int k=0;k<t;k++){
        ShellInsert(L,dlta[k]);
        PrintList(L);
    }
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
    int t=0;
    int d=n/2;
    if(d) {dlta[0]=d;t++;}
    d/=2;
    for(int i=1;d>0;i++) {
        dlta[i]=d;
        d/=2;
        t++;
    }
    ShellSort(L,dlta,t);
    return 0;
}
