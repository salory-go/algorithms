#include<vector>
#include<string>
#include<iostream>

using namespace std;

vector<int> mul(vector<int> &A,int b){
    
    vector<int> C;
    int t=0;
    //注意前面的处理（进1和去0）
    for(int i=0;i<A.size()||t;i++)
    {
        if(i<A.size())t += b*A[i];
        C.push_back(t%10);
        t/=10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');//这里还是记不得
    auto C = mul(A,b);
    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    
}