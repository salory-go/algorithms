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
//整数二分就是区间逼近，两种算法，一种是逼近获取区间右边的值，一种是逼近获取左边的
// 区间更新注意，mid取的是坐标不是值，并且在逼近又区间的时候需要(r+l+1)