/*
PROG: 246A-div2
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,k;
    int x;
    while(cin>>n>>k)
    {
        int cont=0;
        while(n--)
        {
            cin>>x;
            if(x+k<=5) cont++;
        }
        cout<<cont/3<<endl;
    }
    return 0;
}
