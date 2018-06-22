#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100 + 5
using namespace std;
int data[maxn];
int main()
{
    int n;
    int b[10][1000]={0};
    int tem[1000];
    scanf("%d",&n);
    for(int i = 1;i<=n;scanf("%d",&data[i++]));
    for(int w = 0;w<3;w++)
    {
        memset(b,0,sizeof(b));
        for(int i = 1;i<=n;i++)//分配
        {
            int wt = w;
            int t1 = 1;
            while(wt--)
            {
                t1*=10;
            }
            t1 = data[i]/t1;
            int t2 = t1%10;
            int j = 0;
            while(b[t2][j])
            {
                j++;
            }
            b[t2][j] = i;
        }
        int next = 1;
        for(int i = 0;i<=9;i++)
        {
            int k = 0;
            while(b[i][k])
            {
                tem[next++] = data[b[i][k]];
                k++;
            }
        }
        for(int i = 1;i<=n;i++)
        {
            printf("%03d ",tem[i]);
            data[i] = tem[i];
        }
        printf("\n");
    }
    return 0;
}
