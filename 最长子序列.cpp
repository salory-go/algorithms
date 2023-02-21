#include<iostream>
using namespace std;

const int N = 1010;
int f[N],a[N];
int n;

int main(){
    cin>>n;
    int before = -1e9;
    
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++)
    {
        f[i] = 1;
        for(int j=1;j<i;j++)
        {
            
            if(a[j]<a[i])
            {
                 f[i] = max(f[i],f[j]+1);
            }
        }
    }
    
    int ans =0;
    for(int i=1;i<=n;i++) ans = max(ans,f[i]);
    cout<<ans;
    
}
