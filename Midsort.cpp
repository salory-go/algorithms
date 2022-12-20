#include<cstdio>
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int tmp[N];
void Midsort(int q[],int l,int r){
    if (l >= r) return;
    int mid = (l+r)/2;
    Midsort(q, l, mid);
    Midsort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i<=mid&&i>r){
        if(q[i]<q[j]){tmp[k++]=q[i++];}
        else{tmp[k++]=q[j++];}
    }
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];
    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

int main(){
    int n=0;
    cin>>n;
    int q[N],i=0;
    while(i<n){
       cin>>q[i++];
    }
    Midsort(q,n-1,0);
    i=0;
    while(i<n){
       cout<<q[i++]<<" ";
    }
}