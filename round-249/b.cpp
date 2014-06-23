/*
  PROG: 249-div2-B
  ID: fhlove
  TAGS: 贪心，从高位开始枚举
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
void op(int index,string& str,int& sum)
{
    int id=index;
    int n=str.length();
    for(int i=index+1;i<n;i++)
    {
        if(i-index<=sum&&str[id]<str[i]) id=i;
    }
    if(id!=index)
    {
        for(int i=id;i>index;i--)
            swap(str[i],str[i-1]);
        sum=sum-(id-index);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    string str;
    int n;
    while(cin>>str>>n)
    {
        int len=str.length();
        for(int i=0;i<len;i++)
        {
            op(i,str,n);
        }
        cout<<str<<endl;
    }
    return 0;
}
