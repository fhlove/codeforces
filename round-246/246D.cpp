/*************************************************************************
    > File Name: cf-246-2-D.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月17日 星期六 13时44分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<bitset>
#include<sstream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
const int N=100005;
string str;
int next[N];
bool vis[N];
int ans[N];
void get_next(string str,int *next)
{
	int i=0,j=-1;
	int len=str.length();
	next[0]=-1;
	while(i<len)
	{
		if(j==-1||str[i]==str[j])
		{
			i++;
			j++;
			next[i]=j;
		}else j=next[j];
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	while(cin>>str)
	{
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		get_next(str,next);
		int len=str.length();
		int id=len;
		int cont=0;
		while(id)
		{
			cont++;
			vis[id]=1;
			id=next[id];
		}
		
		for(int i=1;i<=len;i++)
			ans[i]=1;

		for(int i=len;i>=1;i--)
			ans[next[i]]+=ans[i];
		cout<<cont<<endl;
		
		for(int i=1;i<=len;i++)
			if(vis[i]) cout<<i<<" "<<ans[i]<<endl;
	}
    return 0;
}
