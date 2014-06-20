/*
PROG: 245-div1-D
ID: fhlove
LANG: C++
tags:见下标看作x，将前缀和看作y，最近点对
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
const LL inf=(1LL)<<62;
struct node
{
    LL x,y;
};
node a[N];
int n;
LL c[N];
bool cmpxy(node x,node y)
{
    if(x.x!=y.x) return x.x<y.x;
    return x.y<y.y;
}
bool cmpy(node x,node y)
{
    return x.y<y.y;
}
inline LL sqr(LL x)
{
    return x*x;
}
LL dis(node x,node y)
{
    return sqr(x.x-y.x)+sqr(x.y-y.y);
}
LL calc(int l,int r)
{
    LL d=inf;
    if(l==r) return inf;
    if(l+1==r) return dis(a[l],a[r]);
    int mid=(l+r)>>1;
    d=min(calc(l,mid),calc(mid+1,r));
    vector<node> v;
    for(int i=l;i<=r;i++)
    {
        if(sqr(a[i].x-a[mid].x)<=d)
        {
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end(),cmpy);
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size()&&sqr(v[i].y-v[j].y)<d;j++)
        {
            d=min(d,dis(v[i],v[j]));
        }
    }
    return d;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    while(cin>>n)
    {
        a[0].x=0;
        a[0].y=0;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            a[i].x=i;
            a[i].y=a[i-1].y+c[i];
        }
        sort(a+1,a+1+n,cmpxy);
        cout<<calc(1,n)<<endl;
    }
    return 0;
}
