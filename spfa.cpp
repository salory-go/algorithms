#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N=2e5+10;
typedef pair<int ,int > PII;

int h[N],w[N],e[N],ne[N],idx;
int dist[N];    //用于记录每一个点距离第一个点的距离
bool st[N];     //用于记录该点的最短距离是否已经确定
int n,m;

void add(int a,int b, int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void spfa()
{
    memset(dist, 0x3f,sizeof dist);     //初始化距离  0x3f代表无限大
    queue<int> q;
    dist[1]=0;  //第一个点到自身的距离为0
    st[1]=true;
    q.push(1);
    
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)  puts("impossible");
    else printf("%d",dist[n]);
}
int main()
{
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);

    while (m--)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        add(x, y, c);
    }
    
    spfa();

    return 0;
}