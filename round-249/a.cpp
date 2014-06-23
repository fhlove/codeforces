/*
  PROG: 249-div2-A
  ID: fhlove
  TAGS:纯模拟
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,m;
    int x;
    while(cin>>n>>m)
    {
        int res=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(sum+x<=m) sum+=x;
            else sum=x,res++;
        }
        cout<<res+1<<endl;
    }
    return 0;
}
