#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 1000


int main() {
    int A[10][MAXN];
    int data[MAXN] = {0};
    int sr[MAXN];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> data[i];
    int w = 3;
    while (w>0) {
        for(int i=0;i<10;i++)
            for(int j=0;j<MAXN;j++)
                A[i][j]=0;
        for (int i = 0; i < n; i++) {
            int tw = w, tmp = data[i],result;
            int power=2;
            while (tw--) {
                int a=(int) pow(10,power);
                result=tmp/a;
                tmp = tmp%a;
                power--;
            }
            int j;
            for (j = 0; A[result][j] != 0; j++);
                A[result][j] = data[i];
        }
        int u = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; A[j][k] != 0; k++)
                sr[u++] = A[j][k];
        }
        for (int j = 0; j < n; j++) {
            cout<<sr[j]<<" ";
            data[j]=sr[j];
        }
        cout<<endl;
        w--;
    }
    return 0;
}
