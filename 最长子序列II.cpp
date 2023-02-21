#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,s;
vector<int> ans;

int main(){
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>s;
        arr[i]= s;
    }
    
    ans.push_back(arr[0]);
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]>ans.back()) ans.push_back(arr[i]);
        else *lower_bound(ans.begin(),ans.end(),arr[i]) = arr[i];
    }
    
    cout<<ans.size();
}
