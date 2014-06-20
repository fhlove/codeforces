/*
PROG: 245C.cpp
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=100005;
vector<int> g[N];
vector<int> res;
int from[N],to[N];
void init(int n)
{
    for(int i=0;i<=n;i++)
        g[i].clear();
    res.clear();
}
void dfs(int rt,int f,int x,int y)
{
    if((from[rt]^x)!=to[rt]) {
        res.push_back(rt);
        x=1-x;
    }
    int n=g[rt].size();
    for(int i=0;i<n;i++)
    {
        if(g[rt][i]==f) continue;
        dfs(g[rt][i],rt,y,x);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n;
    while(cin>>n)
    {
        init(n);
        int u,v;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
            cin>>from[i];
        for(int i=1;i<=n;i++)
            cin>>to[i];
        dfs(1,-1,0,0);
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<endl;
    }
    return 0;
}
