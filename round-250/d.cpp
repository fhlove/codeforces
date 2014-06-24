/*
  PROG: 250-div2-D
  ID: fhlove
  TAGS:
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=100005;
struct node
{
    int u,v;
    int cost;
};
node e[N];
int val[N];
int cont[N],f[N];
bool cmp(node a,node b)
{
    return a.cost>b.cost;
}
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        f[i]=i;
        cont[i]=1;
    }
}
int find(int x)
{
    if(f[x]!=x) return f[x]=find(f[x]);
    return f[x];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,m;
    while(cin>>n>>m)
    {
        init(n);
        for(int i=1;i<=n;i++)
            cin>>val[i];
        for(int i=0;i<m;i++)
        {
            cin>>e[i].u>>e[i].v;
            e[i].cost=min(val[e[i].u],val[e[i].v]);
        }
        sort(e,e+m,cmp);
        double res=0;
        for(int i=0;i<m;i++)
        {
            int pu=find(e[i].u);
            int pv=find(e[i].v);
            if(pu!=pv)
            {
                f[pu]=pv;
                res+=(double)e[i].cost*cont[pv]*cont[pu];
                cont[pv]+=cont[pu];
            }
        }
        printf("%.6lf\n",res*2/(n*1.0*(n-1)));
    }
    return 0;
}
