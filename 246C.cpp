/*
PROG: cf-246-2-C.cpp
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N=100005;
bool is[N];
vector<PII> res;
int id[N];
int num[N];
void init()
{
	memset(is,0,sizeof(is));
	for(int i=2;i<N;i++)
	{
		if(!is[i])
		{
			for(int j=2*i;j<N;j+=i)
				is[j]=1;
		}
	}
}
void solve(int x)
{
	while(id[x]-x>0)
	{
		int i;
		int temp=id[x];
		for(i=temp-x+1;i>=2;i--)
			if(!is[i]) break;
		res.push_back(make_pair(temp-i+1,temp));

		swap(num[temp],num[temp-i+1]);
		id[num[temp]]=temp;
		id[num[temp-i+1]]=temp-i+1;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	init();
	int n;
	while(cin>>n)
	{
		res.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>num[i];
			id[num[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			solve(i);
		}
		cout<<res.size()<<endl;
		for(int i=0;i<res.size();i++)
			cout<<res[i].first<<" "<<res[i].second<<endl;
	}
    return 0;
}
