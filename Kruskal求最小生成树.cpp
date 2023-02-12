#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=200010,M=100010,INF=0x3f3f3f3f;

int n,m,p[N];
struct Edge
{
    int a,b,w;
    
    bool operator<(const Edge &W)const
    {
        return w < W.w;
    }
}edges[N];

int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int Kruskal()
{
    int cnt=0,res=0;
    
    for(int i=0;i<m;i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int x = find(a),y=find(b);
        if(x!=y) 
        {
            p[x] = y;
            cnt ++;
            res+=w;
        }
    }
    if (cnt < n - 1) return INF;
    return res;
}
    
int main(){
    cin>>n>>m;
    int x,y,w;
    for(int i=1;i<=n;i++)p[i] = i;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        edges[i]={x,y,w};
    }
    
    sort(edges,edges+m);
    int t=Kruskal();

    if(t==0x3f3f3f3f) printf("impossible\n");
    else printf("%d\n",t);

    return 0;
}