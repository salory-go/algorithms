#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+10;
int n;
long long a[N],s[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        s[i] = s[i-1]+a[i];
    }
    long long sum = s[n],average = sum/3;
    if(s[n]%3||n<3)cout<<0;
    else{
        long long  js=0,tot=0,ans=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==2*average) ans+=js;
            if(s[i]==average) js++;
        }
        cout<<ans;
    }
    
    
}
