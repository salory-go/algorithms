#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;
vector<PII> alls;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        alls.push_back({l,r});
    }
    sort(alls.begin(),alls.end());

    vector<PII> res;

    for(auto item:alls)
    {
        int l = item.first,r = item.second;
        if(res.size()==0)res.push_back({l,r});
        else{
            int flag=1;
            for(auto it:res)
            {
                //无交集
                if(r<it.first||l>it.second)continue;
                else{
                    it= {min(l,it.first),max(r,it.second)}; 
                    flag =0;
                }
            }
            if(flag)res.push_back ({l,r});
        }
    }
    // for(int i=0;i<res.size();i++)cout<<res[i].first<<" "<<res[i].second<<endl;
    cout<<res.size();
}