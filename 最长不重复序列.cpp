#include<iostream>
#include<string.h>

using namespace std;
const int N = 100010;
int a[N],s[N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    
    int res=0;
    for(int i=0,j=0;i<n;i++)
    {
        s[a[i]]++;   
        while(s[a[i]]>1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(i-j+1,res);
        
    }
    cout<<res;
    
    return 0;
}