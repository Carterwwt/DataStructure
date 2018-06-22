#include <iostream>
#include <cstdio>
#include <cstdlib>
#define maxn 100 + 5
using namespace std;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;scanf("%d",&a[i++]));
    int lmin,lmax,rmin,rmax;
    int tem[n+1];
    int next = 0;
    for(int i = 1;i<n;i*=2)
    {
        next = 0;
        for(lmin = 0;lmin<n-i;lmin = rmax)
        {
            lmax = rmin = lmin+i;
            rmax = rmin + i;
            if(rmax>n) rmax = n;
            while(lmin<lmax&&rmin<rmax) tem[next++] = a[lmin]<a[rmin]?a[lmin++]:a[rmin++];
            while(lmin<lmax) a[--rmin] = a[--lmax];
            while(next>0) a[--rmin]  = tem[--next];
        }
        for(int k = 0;k<n;k++) printf("%d ",a[k]);
        printf("\n");
    }
    return 0;
}
