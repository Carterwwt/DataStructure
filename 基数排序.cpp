
#include <cstdio>
#include <iostream>

void Radixsort(char a[][100],int n,int m)
{
    int count=0;
    for(int y=m-1;y>=0;y--)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                if(a[j][y]>a[j+1][y])
                {
                    for(int tmp=0;tmp<m;tmp++)a[0][tmp]=a[j][tmp];
                    for(int tmp=0;tmp<m;tmp++)a[j][tmp]=a[j+1][tmp];
                    for(int tmp=0;tmp<m;tmp++)a[j+1][tmp]=a[0][tmp];
                    count=1;
                }
            }
            if(count==0){break;}
            count=0;
        }
        for(int tmp=1;tmp<=n;tmp++)printf("%s ",a[tmp]);
        printf("\n");
    }
}

main()
{
    char a[1000][100];
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s",&a[i]);
    for(m=1;a[1][m]!='\0';m++);
    Radixsort(a,n,m);
}
