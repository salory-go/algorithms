#include<iostream>
using namespace std;
const int N = 1010;
int f[N][N],n,V,v[N],w[N];

int main(){
    cin>>n>>V;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=V;j++)
        {
            f[i][j] = f[i-1][j];
            if(j>=v[i]) f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    }    
        
    
    cout<<f[n][V]<<endl;
    
    return 0;
}
