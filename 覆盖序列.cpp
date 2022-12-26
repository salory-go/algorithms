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

    for(int i=0;i<alls.size();i++)
    {
        int l = alls[i].first,r = alls[i].second;
        if(res.size()==0)res.push_back({l,r});
        else{
            int flag=1;
            for(int j=0;j<res.size();j++)
            {
                //无交集
                if(r<res[j].first||l>res[j].second)continue;
                else{
                    res[j] = {min(l,res[j].first),max(r,res[j].second)}; 
                    flag =0;
                }
            }
            if(flag)res.push_back ({l,r});
        }
    }
    // for(int i=0;i<res.size();i++)cout<<res[i].first<<" "<<res[i].second<<endl;
    cout<<res.size();
}