#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
int h[N],sz=0,hp[N],ph[N];

void heap_swap(int a,int b)
{
    swap(h[a],h[b]);
    
    swap(hp[a],hp[b]);
    
    swap(ph[hp[a]],ph[hp[b]]);
}
void down(int u)
{
    int t =u;
    if(2*u<=sz&&h[2*u]<h[t])t = 2*u;
    if(2*u+1<=sz&&h[2*u+1]<h[t])t = 2*u+1;
    if(u!=t)
    {
        heap_swap(h[t],h[u]);
        down(t);
    }
}

void up(int u)
{
    if(u/2>0&&h[u]<h[u/2]) 
    {
        heap_swap(u,u/2);
        up(u>>1);
    }
}

int main(){
    int n;
    cin>>n;
    int m=0;
    while(n--)
    {
        string op;
        int k,x; 
        cin>>op;
        if(op=="I")
        {
            scanf("%d",&x);
            m++;
            h[++sz] = x;
            hp[sz]=m;
            ph[m]=sz;
            up(sz);
        }
        else if(op=="PM")
        {
            printf("%d\n",h[1]);
        }
        else if(op=="DM")
        {
            heap_swap(1,sz--);  
            down(1);
        }
        else if(op=="D")
        {
            scanf("%d",&k);
            heap_swap(ph[k],sz--);  
            down(ph[k]);up(ph[k]);
        }
        else {
            cin>>k>>x;
            h[ph[k]] = x;
            down(ph[k]);up(ph[k]);
        }
    }
}