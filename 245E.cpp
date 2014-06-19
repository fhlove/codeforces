/*
PROG: 245E-div2
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=30;
int c[N];
bool vis[N];
int n;
void init()
{
    memset(vis,0,sizeof(vis));
}
/*
先排序，然后dfs暴力枚举。
dfs以pre为父节点的子树是否存在
*/
bool dfs(int pre,int cur,int child)
{
    if(pre==n) return 1;
    if(cur+1==c[pre])
    {
        if(child!=1&&dfs(pre+1,0,0)) return 1;
        return 0;
    }
    int tot=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&cur+c[i]<c[pre]&&tot!=c[i])
        {
            tot=c[i];
            vis[i]=1;
            if(dfs(pre,cur+c[i],child+1)) return 1;
            vis[i]=0;
        }
    }
    return 0;
}
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c[i];
    sort(c,c+n);
    if(c[n-1]==n&&dfs(0,0,0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    init();
    solve();
    return 0;
}
