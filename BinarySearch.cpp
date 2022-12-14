#include<cstdio>
#include<iostream>
using namespace std;

int BindarySearch(int data[],int length,int k){
    int left,right,mid;
    left = 0;
    right = length;
    
    while(left<=right){
        mid = (left+right)/2;
        if(mid<k)left = mid+1;
        else if(mid>k)right = mid-1;
        else return data[mid];
    }
    return 0;
}

int main(){
    int data[10];
    for(int i=0;i<10;i++){
        data[i] = i*100;
    }
    cout<<BindarySearch(data,10,6);
}