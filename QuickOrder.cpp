#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5+10;
int q[N];
void qucik_srot(int q[],int l,int r)
{
    int i=l+1,j = r-1,x = q[(i+j)/2];
    while(i<j)
    {
        do i++;while(q[i]<=x);
        do j--;while(q[j]>=x);
        if(i<j) swap(q[i],q[j]);
    }
    qucik_srot(q,l,j),qucik_srot(q,j+1,r);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    qucik_srot(q,0,n-1);
    for(int i=0;i<n;i++)printf("%d",q[i]);
}
//快速排序和归并排序的递归都是一样，指针间隔指针都相同，只需要其中一个移位。快速排序时，端点值内移，先do后while。
// 递归最后的l>=r忘记，并且是<不是<=,递归是用j变量,不是i，j都可