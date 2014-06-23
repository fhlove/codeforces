/*
PROG: 249-div2-C
ID: fhlove
TAGS: 纯模拟
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int N=2005;
char str[N][N];
void solve(int n)
{

    memset(str,0,sizeof(str));
    int x=0,y=1000;
    int miny=1000,maxy=1000;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        for(int j=x;j<x+a;j++)
        {
            if(i%2==0) {
                str[y][j]='/';
                y++;
                maxy=max(maxy,y);
            }else {
                y--;
                str[y][j]='\\';
                miny=min(miny,y);
            }
        }
        x+=a;
    }
    for(int i=maxy-1;i>=miny;i--)
    {
        for(int j=0;j<x;j++)
            if(str[i][j]!=0) cout<<str[i][j];
            else cout<<' ';
        cout<<endl;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n;
    while(cin>>n)
    {
        solve(n);
    }
    return 0;
}
