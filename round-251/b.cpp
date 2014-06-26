/*
  PROG: 251-div2-B
  ID: fhlove
  TAGS: 排序直接算
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n;
    LL x;
    while(cin>>n>>x)
    {
        vector<LL> v;
        LL y;
        for(int i=0;i<n;i++)
        {
            cin>>y;
            v.push_back(y);
        }
        sort(v.begin(),v.end());
        LL res=0;
        LL num=1;
        for(int i=0;i<n;i++)
        {
            res=res+v[i]*max(x,num);
            x--;
        }
        cout<<res<<endl;
    }
    return 0;
}
