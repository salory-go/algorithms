#include<iostream>
#include<algorithm>
using namespace std;
/*
1.插入一个数          heap[++size] = x;up[size];
2.求集合中的最小值     heap[1];
3.删除最小值          heap[1] = heap[size--];down(1);
4.删除任意一个元素     heap[k] = heap[size--];down(k);up[k];
5.修改任意一个元素     heap[k] = x;down(k);up[k];
*/
const int N = 1e5+10;
int q[N],sz;
int n,m;

void down(int u)
{
    int t =u;
    if(2*u<=sz&&q[2*u]<q[t])t = 2*u;
    if(2*u+1<=sz&&q[2*u+1]<q[t])t = 2*u+1;
    if(u!=t)
    {
        swap(q[t],q[u]);
        down(t);
    }
}

void up(int u)
{
    while(u/2&&q[u]<q[u/2])
    {
        swap(q[u],q[u/2]);
        u/=2;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&q[i]);
    sz = n;
    
    for(int i=n/2;i;i--)down(i);
    
    while(m--)
    {
        cout<<q[1]<<" ";
        q[1] = q[sz--];
        down(1);
    }
}