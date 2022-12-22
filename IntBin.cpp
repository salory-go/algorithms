#include<cstdio>
#include<iostream>

using namespace std;
const int N = 100010;
int q[N];

int main(){
    int n,m,i=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>q[i];
    int r=n-1,l=0;
    while(m--){
        int k;
        cin>>k;
        int r=n-1,l=0;
        while(l<r){
            int mid = (r+l)/2;
            if(q[mid]>=k)r=mid;
            else l=mid+1;
        }
        if(q[r]!=k)cout<<"-1 -1"<<endl;
        else{
            cout<<l<<" ";
            int r=n-1;
            while(l<r){
                int mid = (r+l+1)/2;
                if(q[mid]<=k)l=mid;
                else r=mid-1;
            }
            cout<<l<<endl;
        }
    }
}