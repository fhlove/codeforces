/*
  PROG: 250-div2-B
  ID: fhlove
  TAGS: 位运算，枚举,贪心，从大的数字开始选
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int low_bit(int x)
{
    for(int i=0;i<25;i++)
    {
        int y=(1<<i);
        if(x&y) return y;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int sum,limit;
    while(cin>>sum>>limit)
    {
        vector<int> res;
        for(int i=limit;i>0;i--)
        {
            int bit=low_bit(i);
            if(bit<=sum)
            {
                sum-=bit;
                res.push_back(i);
            }
        }
        if(sum==0)
        {
            cout<<res.size()<<endl;
            for(int i=0;i<res.size();i++)
                cout<<res[i]<<' ';
            cout<<endl;
        }else cout<<-1<<endl;
    }
    return 0;
}
