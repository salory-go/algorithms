#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
int q[N],Size[N];



int find(int x)
    {
        if (q[x] != x) q[x] = find(q[x]);
        return q[x];
    }

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i ++ )
    {
        q[i] = i;
        Size[i] = 1;
    }
    
    while(m--)
    {
        string op;
        int a,b;
        cin>>op;
        if(op=="C")
        {
            cin>>a>>b;
            if(find(a)==find(b)) continue;
            Size[find(b)]+=Size[find(a)];
            q[find(a)] = find(b);
            
        }
        else if(op=="Q1")
        {
            cin>>a>>b;
            if(find(a)==find(b))printf("Yes\n");
            else printf("No\n");
        }
        else
        {
            cin>>a;
            printf("%d\n",Size[find(a)]);
        }
        
    }
    return 0;
}