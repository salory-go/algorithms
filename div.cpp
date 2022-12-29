#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;
// 只需要这里加&就行
vector<int> div(vector<int> &A,int b,int &t){
    
    vector<int> C;
    // 除法要从前面开始
    for(int i=A.size()-1;i>=0;i--)
    {
        // 记得乘10
        t = A[i]+t*10;
        C.push_back(t/b);
        t %=b;
    }
    // 前面的0没用，后面的0有用，所以需要反转然后消0
    reverse(C.begin(),C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    int t=0;
    auto C = div(A,b,t);
    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    cout<<endl<<t;
    
}