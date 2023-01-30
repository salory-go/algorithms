#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5+3;
int e[N],ne[N],idx=0,h[N];

int insert(int x)
{
    int k=(x%N+N)%N;
    e[idx] = x;
    ne[idx]= h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x) return true;
    }
    return false;
}

int main(){
    int n,x;
    cin>>n;
    string op;
    
    memset(h,-1,sizeof h);
    
    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I") {
            insert(x);
        } else {
            if (find(x)) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    return 0;
}