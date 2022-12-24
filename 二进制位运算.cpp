#include<iostream>


using namespace std;

int lowbit(int x)
{
    return x&-x;    
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int sum=0,x;
        cin>>x;
        while(x)x-=lowbit(x),sum++;
        cout<<sum<<" ";
    }
}