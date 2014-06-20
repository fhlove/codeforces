/*
PROG: 247-div2-A
ID: flhove
TAGS: 纯模拟
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    string str;
    int a[4];
    while(cin>>a[1]>>a[2]>>a[3]>>a[4])
    {
        cin>>str;
        int res=0;
        for(int i=0;i<str.length();i++)
            res+=a[str[i]-'0'];
        cout<<res<<endl;
    }
    return 0;
}
