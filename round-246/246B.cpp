/*
PROG: 246-div2-D
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int x[N],y[N];
int cont[N];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n;
    while(cin>>n)
    {
        memset(cont,0,sizeof(cont));
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
            cont[x[i]]++;
        }
        for(int i=0;i<n;i++)
            cout<<(n-1+cont[y[i]])<<"  "<<(n-1-cont[y[i]])<<endl;
    }
    return 0;
}
