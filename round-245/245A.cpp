/*************************************************************************
PROG: cf-245-2-A.cpp
ID: fhlove
LANG: C++ 
************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int N=105;
int color[N];
vector<pair<int,int> > v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int x,y;
    int n,m;
    while(cin>>n>>m) {
        for(int i=0;i<n;i++)
        {
            cin>>x;
            v.push_back(make_pair(x,i));
        }
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            color[v[i].second]=i%2;
        }
        for(int i=0;i<n;i++)
        {
            cout<<color[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

