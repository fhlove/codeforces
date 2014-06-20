/*
PROG: 247-div2-B
ID: fhlove
TAGS: 纯暴力
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define LL long long
int g[10][10];
LL ans;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
            scanf("%d", &g[i][j]);
    }
    ans = 0;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i != j)
            {
                for (int k = 1; k <= 5; k++)
                {
                    if (k != j && k != i)
                    {
                        for (int l = 1; l <= 5; l++)
                        {
                            if (l != k && l != i && l != j)
                            {
                                for (int p = 1; p <= 5; p++)
                                {
                                    if (p != l && p != i && p != j && p != k)
                                    {
                                 //       printf("i = %d, j = %d, k = %d, l = %d, p = %d\n", i, j, k, l, p);
                                        LL sum = g[i][j] + g[j][i] + g[j][k] + g[k][j] + 2 * (g[l][p] + g[p][l] + g[k][l] + g[l][k]);
                                        ans = max(ans, sum);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
