/*
  PROG: 250-div2-C
  ID: fhlove
  TAGS: 贪心，从价值最大的开始删除，这样该点对其他点的影响就减少了
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1005;
typedef pair<int,int> pii;
set<int> g[N];
int val[N];
int n;
void init(int n)
{
    for(int i=0;i<=n;i++)
        g[i].clear();
}
int calc(int i)
{
    int res=0;
    for(set<int>::iterator it=g[i].begin();it!=g[i].end();it++)
    {
        res+=(val[*it]);
    }
    g[i].clear();
    for(int j=1;j<=n;j++)
    {
        g[j].erase(i);
    }
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int m;
    int cost;
    int u,v;
    while(cin>>n>>m)
    {
        init(n);
        vector<pii> q;
        for(int i=1;i<=n;i++)
        {
            cin>>cost;
            val[i]=cost;
            q.push_back(make_pair(cost,i));
        }
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            g[u].insert(v);
            g[v].insert(u);
        }
        int res=0;
        sort(q.begin(),q.end());
        for(int i=n-1;i>=0;i--)
        {
            pii x=q[i];
            int t=calc(x.second);
            res+=t;
            //   cout<<t<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}
