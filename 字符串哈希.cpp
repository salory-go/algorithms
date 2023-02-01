#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e5,P=131;
ULL h[N],p[N];


int query(int l,int r)
{
    return h[r] - h[l-1]*p[r-l+1];
}

int main(){
    p[0]=1;
    int n,m;
    cin>>n>>m;
    string x;
    cin>>x;
    
    for(int i=0;i<n;i++)
    {
        p[i+1] = p[i]*P;
        h[i+1] = h[i]*P+x[i];
    }
    
    while(m--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(query(l1,r1)==query(l2,r2)) puts("Yes");
        else puts("No");
    }
}