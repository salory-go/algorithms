#include<vector>
#include<string>
#include<iostream>

using namespace std;
//要先写一个比较函数，总是把数大的来减，最后再看要不要加符号
bool cmp(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size())return A.size()>B.size();
    for(int i=A.size()-1;i>=0;i--)
        if(A[i]!=B[i])
            return A[i]>B[i];
    return true;
    
}

vector<int> sub(vector<int> &A,vector<int> &B){
    
    vector<int> C;
    // t只能是1或者0，A[i]先减t再减B[i]（如果B还有）,对t的更新要注意t=0的归类
    for(int i=0, t=0;i<A.size();i++)
    {
        t = A[i]-t;
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10);
        if(t<0)t=1;
        else t=0;
    }
    // 结尾要去0
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}

int main(){
    string a,b;
    cin>>a>>b;
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
    if(cmp(A,B)){
        auto C = sub(A,B);
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }
    else{
        auto C = sub(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }
    
}