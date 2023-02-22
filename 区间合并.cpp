#include<iostream>

using namespace std;
const int N = 310;

int n,s[N],f[N][N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i],s[i]+=s[i-1];
    
    
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=len+i-1;
            f[i][j] = 1e9;
            for(int k=i;k<j;k++)
            {
                f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
            }
        }
    }
    
    cout<<f[1][n];
}
