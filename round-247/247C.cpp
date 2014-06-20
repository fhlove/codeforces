/*************************************************************************
    > File Name: cf-247-2-C.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年06月04日 星期三 20时07分31秒
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
const int N=1000;
const int mod=1e9+7;
int n,d,k;
int dp[N][2];
void add(int &a,int b)
{
	a=(a+b)%mod;
}
int calc(int sum,int is)
{
	if(dp[sum][is]!=-1) return dp[sum][is];

	if(sum==0) return dp[sum][is]=is;
	
	dp[sum][is]=0;
	
	for(int i=1;i<=k;i++)
	{
		if(sum-i<0) break;
		if(is==1||i>=d) add(dp[sum][is],calc(sum-i,1));
		else add(dp[sum][is],calc(sum-i,0));
	}

	return dp[sum][is];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	while(cin>>n>>k>>d)
	{
		memset(dp,-1,sizeof(dp));
		int res=calc(n,0);
		cout<<res<<endl;
	}
    return 0;
}
