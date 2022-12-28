#include<cstdio>
#include<iostream>
using namespace std;

const int N = 1e6+10;

int head=-1,ed = -1,q[N],a[N];

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    head = 0,ed = -1;
    for(int i=0;i<n;i++)
    {
        if(head<=ed&&q[head]<i-k+1)head++;
        while(a[q[ed]]>=a[i]&&head<=ed)ed--;
        q[++ed] = i;
        if(i>=k-1)printf("%d ",a[q[head]]);
    }
    cout<<endl;
    head = 0,ed = -1;
    for(int i=0;i<n;i++)
    {
        if(head<=ed&&q[head]<i-k+1)head++;
        while(a[q[ed]]<=a[i]&&head<=ed)ed--;
        q[++ed] = i;
        if(i>=k-1)printf("%d ",a[q[head]]);
    }
}