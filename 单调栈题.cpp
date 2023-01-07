#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5+10;
int stk[N],head=-1;

int main(){
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        while(head!=-1&&stk[head]>=x)head--;
        if(head==-1)printf("-1 ");
        else printf("%d ",stk[head]);
        stk[++head] = x;
    }
    return 0;
}
// 比右边大的数就不需要存了