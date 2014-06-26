/*
  PROG: 251-div2-D
  ID: fhlove
  TAGS: 三分搜索，使得第一个数组中的数字大于等于 x，第二个数组数字小于等于 x，三分 x
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005;
typedef long long LL;
LL a[N],b[N];
LL calc(LL x,int n,int m)
{
    LL res=0;
    for(int i=0;i<n;i++)
        if(a[i]<x) res+=(x-a[i]);
        else break;
    for(int j=m-1;j>=0;j--)
        if(b[j]>x) res+=(b[j]-x);
        else break;
    return res;
}
void solve(int n,int m)
{
    LL l=0;
    LL r=1e9;
    while(r-l>2)
    {
        LL dis=(r-l)/3;
        LL mid=l+dis;
        LL mmid=mid+dis;
        if(calc(mid,n,m)<=calc(mmid,n,m)) r=mmid-1;
        else l=mid+1;
    }
    cout<<min(calc(l,n,m),calc(r,n,m))<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int j=0;j<m;j++)
            cin>>b[j];
        sort(a,a+n);
        sort(b,b+m);
        solve(n,m);
    }
    return 0;
}
