/*
  PROG: 251-div2-E
  ID: fhlove
  TAGS:另f(n,m,x)表示将 n分成 m个数字相加的和而且最小公倍数为 x，g(n,m)表示将 n分成 m个数字的和总共有多少种情况。
       f(n,m,1)=g(n,m)-(k>1 && k|n) ∑f(n,m,k)
       f(n,m,1)=g(n-m)-(k>1 && k|n) ∑f(n/k,m,1)
       g(n,m)=(k<n && k|n) ∑f(n/k,m,1)
       另 d=n/k
       g(n,m)=(d|n) ∑f(d,m,1) --------------> 满足莫比乌斯反演公式
       --------------> f(n,m,1)=(d|n) ∑g(n/d,m)*μ(d)

       莫比乌斯函数μ(n)的定义域是N
       2) μ(1)=1
       3) 当n存在平方因子时，μ(n)=0
       4) 当n是素数或奇数个不同素数之积时，μ(n)=-1
       5) 当n是偶数个不同素数之积时，μ(n)=1
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
const LL mod=1e9+7;
vector<LL> div[N];
LL f[N];
LL rev[N];
LL mob[N];
int mu(int n)
{
    int cont=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n/=i;
            cont++;
            if(n%i==0) return 0;
        }
    }
    if(n!=1) cont++;
    if(cont&1) return -1;
    return 1;
}
LL pow(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1) res*=a;
        b>>=1;
        a*=a;
        res%=mod;
        a%=mod;
    }
    return res;
}
void init()
{
    f[0]=1;
    rev[0]=1;
    for(int i=1;i<N;i++)
    {
        mob[i]=mu(i);
        f[i]=(i*f[i-1])%mod;
        rev[i]=pow(f[i],mod-2);
    }
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            div[j].push_back(i);
        }
    }
}
LL c(int n,int m)
{
    if(n<m) return 0;
    return (((f[n]*rev[m])%mod)*rev[n-m])%mod;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    init();
    int q;
    int n,m;
    cin>>q;
    while(q--)
    {
        cin>>n>>m;
        LL res=0;
        for(int i=0;i<div[n].size();i++)
        {
            res+=(mob[div[n][i]]*c(n/div[n][i]-1,m-1))%mod;
            res=(res%mod+mod)%mod;
        }
        cout<<res<<endl;
    }
    return 0;
}
