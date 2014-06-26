/*
  PROG: 251-div2-C
  ID: fhlove
  TAGS: 找规律构造,先构造和为偶数的，再构造和为奇数的
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,p,k;
    int x;
    while(cin>>n>>k>>p)
    {
        int ec=p;
        int oc=k-p;
        vector<int> ev,od;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x&1) od.push_back(x);
            else ev.push_back(x);
        }
        int e=ev.size();
        int o=od.size();
        if(oc>od.size()||(od.size()-oc)%2||(ev.size()+(od.size()-oc)/2 < p)) cout<<"NO"<<endl;
        else {
            puts("YES");
            int i;
            for(i=0;i<p&&i<k-1&&e>0;i++)
                cout<<1<<' '<<ev[--e]<<endl;
            for(;i<p&&i<k-1&&o>1;i++,o-=2)
                cout<<2<<' '<<od[o-1]<<' '<<od[o-2]<<endl;
            for(;i<k-1;i++)
                cout<<1<<' '<<od[--o]<<endl;
            cout<<o+e<<' ';
            for(;o>0;) cout<<od[--o]<<' ';
            for(;e>0;) cout<<ev[--e]<<' ';
            cout<<endl;
        }
    }
    return 0;
}
