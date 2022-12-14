#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e6+10;
int q[N],a[N];
void Binsort(int q[],int l,int r)
{
    if(l>=r) return;
    int mid = (l+r)/2;
    Binsort(q,l,mid),Binsort(q,mid+1,r);
    int i = l,j = mid+1,k = 0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])a[k++] = q[i++];
        else a[k++] = q[j++];
    }
    while(i<=mid)a[k++] = q[i++];
    while(j<=r)a[k++] = q[j++];
    for(int i=l,j=0;i<=r;i++,j++)q[i] = a[j];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    Binsort(q,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",q[i]);
}
//无处理的二分递归，然后注意<=，注意合并数组
//指针不要搞错了，归并的逻辑不要搞错了