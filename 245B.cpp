/*************************************************************************
PROG: cf-245-2-B.cpp
ID: fhlove
LANG: C++
************************************************************************/

#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
const int N=100005;
int c[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int n,k,x;
    while(cin>>n>>k>>x)
      {
        for(int i=0;i<n;i++)
          {
            cin>>c[i];
          }
        int ans=0;
        for(int i=1;i<n;i++)
          {
            int k,j;
            if(c[i]==c[i-1]&&c[i]==x)
              {
                int l=i-2;
                int r=i+1;
                int res=2;
                while(1)
                  {
                    int k1=0;
                    int k2=0;
                    for(j=l;j>=0;j--)
                      {
                        if(c[j]!=c[l]) break;
                        k1++;
                      }
                    for(k=r;k<n;k++)
                      {
                        if(c[k]!=c[r]) break;
                        k2++;
                      }
                    if(k1+k2>=3&&c[l]==c[r])
                      {
                        l=j;
                        r=k;
                        res+=k1+k2;
                      }else {
                      ans=max(ans,res);
                      break;
                    }
                  }
              }
          }
        cout<<ans<<endl;
      }
    return 0;
}

