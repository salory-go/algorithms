#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5+10;
int a[N];
int main(){
    int n;
    cin>>n;
    LL res =0;

    for(int i=0;i<n;i++) cin>>a[i];
    
    sort(a,a+n);
    
    for(int i=0;i<n;i++) res+=a[i]*(n-i-1);
    
    cout<<res;
}
