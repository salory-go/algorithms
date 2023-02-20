#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 2010;
int f[N];

struct Good
{
    int v,w;
};

int main(){
    vector<Good> Goods;
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        int v,w,s;
        cin>>v>>w>>s;
        for(int k=1;k<=s;k*=2)
        {
            s-=k;
            Goods.push_back({v*k,w*k});
        }
        if(s) Goods.push_back({v*s,w*s});
    }

    
    for(auto g:Goods)
    {
        for(int j=m;j>=g.v;j--)
        {
            f[j] = max(f[j],f[j-g.v]+g.w);
        }
    }
    
    cout<<f[m];
    return 0;
}
