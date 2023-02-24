#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5+10;

struct Range
{
    int l,r;
    bool operator< (const Range &W)const
    {
        return  l < W.l;
    }
    
}range[N];

int main(){
    int n,st,ed;
    cin>>st>>ed>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        range[i] = {a,b};
    }
    
    bool success;
    sort(range,range+n);
    
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int j = i,r = -2e9;
        while(j<n&&range[j].l<=st)
        {
            r = max(r,range[j].r);
            j++;
        }
        
        if(r<st){ success = false;break;}
        st = r;
        res++;
        if(ed<=r){ success = true; break;}
        
        i = j-1;
    }
    
    if(success) cout<<res;
    else cout<<-1;
    
    
}
