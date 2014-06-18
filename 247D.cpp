/*************************************************************************
    > File Name: cf-247-2-D.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年06月04日 星期三 21时11分32秒
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
typedef long long LL;
const int N=66;
const LL bit=1;
LL k;
LL c[N][N];
void init()
{
	memset(c,0,sizeof(c));
	c[0][0]=1;
	for(int i=1;i<N;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
}
inline LL sum(LL x)
{
	int cont=0;
	LL res=0;
	for(int i=61;i>=0;i--)
	{
		if(x&(bit<<i))
		{
			if(k-cont>=0) res+=c[i][k-cont];
			cont++;	
		}
	}
	return res;
}
inline LL calc(LL n)
{
	LL nn=2*n;
	return sum(nn)-sum(n);
}
LL solve(LL m)
{
	LL l=1;
	LL r=1e18;
	LL res=0;
	while(l<=r)
	{
		LL mid=(l+r)>>1;
		LL temp=calc(mid);
		if(temp>=m)
		{
			res=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	LL m;	
	init();	
	while(cin>>m>>k)
	{
		cout<<solve(m)<<endl;
	}
    return 0;
}
