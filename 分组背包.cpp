#include<iostream>
using namespace std;

const int N = 110;
int f[N],v[N],w[N];
int n,m,s;

int main(){
    cin>>n>>m;
    while(n--)
    {
        cin>>s;
        for(int j=0;j<s;j++) cin>>v[j]>>w[j];
        for(int j=m;j>=0;j--)
            for(int k=0;k<s;k++)
                if(j>=v[k]) 
                    f[j] = max(f[j],f[j-v[k]]+w[k]);
    }
    cout<<f[m];
    return 0;
}
