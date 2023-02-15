#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5+10,M = 2*N;
int h[N],e[M],ne[M],idx;
int color[N],n,m;

bool dfs(int u,int c)
{
    color[u] = c;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(color[j]==0)
        {
            if(!dfs(j,3-c)) return false;
        }else if(color[j]==c)  return false;
    }
    return true;
}

bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            if(!dfs(i,1)) return false;
        }
    }
    return true;
}

void add(int a,int b)
{
    e[idx] = b , ne[idx] = h[a],h[a] = idx++;
}

int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    
    if(check()) puts("Yes");
    else puts("No");
}