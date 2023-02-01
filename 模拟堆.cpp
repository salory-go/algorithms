#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+10;

int s[N],siz;

void down(int u)
{
    int t = u;
    if(2*u<=siz&&s[2*u]<s[t]) t=2*u;
    
    if(2*u+1<=siz&&s[2*u+1]<s[t]) t=2*u+1;
    
    if(u!=t)
    {
        swap(s[t],s[u]);
        down(t);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    siz = n;
    
    for(int i=n/2;i;i--)down(i);
    
    while(m--)
    {
        printf("%d ",s[1]);
        s[1] =s[siz--];
        down(1);
    }
}