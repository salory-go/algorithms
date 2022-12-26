#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1e6+10;
int q[N],a[N];


void merge_sort(int q[],int l,int r)
{
    if(l>=r)return;
    
    int mid = (l+r)/2;
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);
    
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])a[k++] = q[i++];
        else a[k++] = q[j++];
    }
    while(i<=mid)a[k++] = q[i++];
    while(j<=r)a[k++] = q[j++];
    
    for(int i = l,j=0;i<=r;i++,j++)q[i] = a[j];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>q[i];
    
    merge_sort(q,0,n-1);
    
    for(int i=0;i<n;i++)cout<<q[i]<<" ";
    
    return 0;
}
//无处理的二分递归，然后注意<=，注意合并数组