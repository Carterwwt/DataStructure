#include <iostream>
using namespace std;
#define MAXN 1000
typedef struct Sqlist{
    int A[MAXN];
    int length;
}SqList;


void print(SqList H){
    for(int i=1;i<=H.length;i++)
        cout<<H.A[i]<<" ";
    cout<<endl;
}

void HeadAjust(SqList &H,int s,int m){
    int tmp=H.A[s];
    for(int j=s<<1;j<=m;j*=2){
        if(j<m&&H.A[j]<H.A[j+1]) j++;
        if(!(tmp<H.A[j])) break;
        H.A[s]=H.A[j];
        s=j;
    }
    H.A[s]=tmp;
}

void HeapSort (SqList &H){
    for(int i=H.length/2;i>0;i--)
        HeadAjust(H,i,H.length);
    print(H);
    for(int i=H.length;i>1;i--){
        int tmp=H.A[1];
        H.A[1]=H.A[i];
        H.A[i]=tmp;
        HeadAjust(H,1,i-1);
        print(H);
    }
}

int main(){
    int n;
    SqList H;
    cin>>n;
    H.length=n;
    for(int i=1;i<=n;i++)
        cin>>H.A[i];
    HeapSort(H);
    return 0;
}
