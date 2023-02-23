#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

int f[N][2];
int h[N],e[N],ne[N],idx,happy[N];
bool hasfather[N];

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a];h[a] = idx++;
}

void dfs(int u)
{
    f[u][1] = happy[u];
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j = e[i];
        dfs(j);
        
        f[u][0] += max(f[j][0],f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>happy[i];
    
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(b,a);
        hasfather[a] = true;
    }
    
    int boot=1;
    while(hasfather[boot]) boot++;
    
    dfs(boot);
    
    cout<<max(f[boot][0],f[boot][1]);
}
