#include <bits/stdc++.h>
using namespace std;
#define maxn 100
// 经典圆圈剔除数字

void turns(int n,int k,int a[],int last){
    //这里的核心是把被剔除的内容归为0，然后循环跳过
    int i=0;
    int j=0;
    for(i=last;j<k;i++){
        
        if(a[i]!=0){
            j++;
            // cout<<a[i]<<endl;
        }
        if(i==n)i=-1;
    }
    i--;
    cout<<a[i]<<endl;
    a[i] = 0;
}

int main(){
    int n=0;
    cin>>n;
    // 输入10可检验
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    
    turns(10,4,a,0);
    turns(10,4,a,4);
    turns(10,4,a,8);
    turns(10,4,a,2);
    turns(10,4,a,7);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    
    

    
    
}
