#include<iostream>
using namespace std;
const int N = 1e5+10;
int q[N],s[N];

int main(){
    int n,res=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>q[i];
    for(int i=0,j=0;i<n;i++)
    {
        s[q[i]]++;
        while(s[q[i]]>1)s[q[j++]]--;
        res = max(res,i-j+1);
    }
    cout<<res;
}
//双指针是指外for内while，check序列是否重复用的是新数组存数字出现次数