/*
PROG: 245D-div2
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=1005;
int mat[N][N];
int ul[N][N],ur[N][N],dl[N][N],dr[N][N];
void init(int n,int m)
{
    memset(ul,0,sizeof(ul));
    memset(ur,0,sizeof(ur));
    memset(dl,0,sizeof(dl));
    memset(dr,0,sizeof(dr));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ul[i][j]=max(ul[i-1][j],ul[i][j-1])+mat[i][j];
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            dr[i][j]=max(dr[i+1][j],dr[i][j+1])+mat[i][j];

    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            ur[i][j]=max(ur[i-1][j],ur[i][j+1])+mat[i][j];
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
            dl[i][j]=max(dl[i+1][j],dl[i][j-1])+mat[i][j];
}
void solve(int n,int m)
{
    int res=0;
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
            res=max(res,max(ul[i-1][j]+dr[i+1][j]+dl[i][j-1]+ur[i][j+1],
                            ul[i][j-1]+dr[i][j+1]+dl[i+1][j]+ur[i-1][j]));
    cout<<res<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&mat[i][j]);
    init(n,m);
    solve(n,m);
    return 0;
}
