/*
  PROG: 249-div2-D
  ID: fhlove
  TAGS:暴力枚举合法的三角形，先预处理四个方向上的 '1'的个数，分四种情况：
  1: .
     *
     * *
     *
     ...............
  2:
    .
    . *
    .***...
  3:
    .****
    . * *
    .  **
    .   *
    .........

  4:
    .*
    .**
    .* *
    .*  *
    .*   *
    .******
    .............
 */
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=405;
int l[N][N],u[N][N],ul[N][N],ur[N][N];
char str[N][N];
int n,m;
void init()
{
    memset(l,0,sizeof(l));
    memset(u,0,sizeof(u));
    memset(ul,0,sizeof(ul));
    memset(ur,0,sizeof(ur));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int add=str[i][j]-'0';
            l[i][j]=l[i][j-1]+add;
            u[i][j]=u[i-1][j]+add;
            ul[i][j]=ul[i-1][j-1]+add;
            ur[i][j]=ur[i-1][j+1]+add;
        }
}
inline bool isok(int x,int y)
{
    return (x>=1&&x<=n&&y>=1&&y<=m&&str[x][y]=='0');
}
inline int calc(int x,int y)
{
    if(str[x][y]=='1') return 0;
    int res=0;
    for(int i=1;isok(x,y+i)&&isok(x-i,y);i++)
        if(ul[x][y+i]==ul[x-i-1][y-1]) res++;
    for(int i=1;isok(x+i,y)&&isok(x,y-i);i++)
        if(ul[x-1][y-i-1]==ul[x+i][y]) res++;

    for(int i=1;isok(x,y-i)&&isok(x-i,y);i++)
        if(ur[x][y-i]==ur[x-i-1][y+1]) res++;
    for(int i=1;isok(x+i,y)&&isok(x,y+i);i++)
        if(ur[x+i][y]==ur[x-1][y+i+1]) res++;

    for(int i=1;isok(x+i,y-i)&&isok(x+i,y+i);i++)
        if(l[x+i][y-i-1]==l[x+i][y+i]) res++;
    for(int i=1;isok(x-i,y-i)&&isok(x-i,y+i);i++)
        if(l[x-i][y-i-1]==l[x-i][y+i]) res++;

    for(int i=1;isok(x-i,y+i)&&isok(x+i,y+i);i++)
        if(u[x-i-1][y+i]==u[x+i][y+i]) res++;
    for(int i=1;isok(x-i,y-i)&&isok(x+i,y-i);i++)
        if(u[x-i-1][y-i]==u[x+i][y-i]) res++;
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        init();
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                res+=calc(i,j);
        cout<<res<<endl;
    }
    return 0;
}
