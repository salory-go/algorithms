#include<iostream>
using namespace std;
const int N = 1e5+10;
int e[N],Le[N],Re[N],idx;
// 初始化就要想好有左链表和右链表，并且下标要从2开始
void init()
{
    Le[1] = 0;
    Re[0] = 1;
    idx = 2;
}
// insert 的先后顺序
void insert(int k,int x)
{
    e[idx] = x;
    Re[idx] = Re[k];
    Le[idx] =  k;
    Le[Re[k]] = idx;
    Re[k] = idx++;
    
}

void remove(int k)
{
    Re[Le[k]] = Re[k];
    Le[Re[k]] = Le[k];
}

int main(){
    int n;
    cin>>n;
    init();
    while(n--)
    {
        // 万恶的字符串
        string op;
        cin>>op;
        if(op=="R")
        {
            int x;
            cin>>x;
            insert(Le[1],x);
        }
        else if(op=="L")
        {
            int x;
            cin>>x;
            insert(0,x);
        }
        else if(op=="IL")
        {
            int x,k;
            cin>>k>>x;
            insert(Le[k+1],x);
        }else if(op=="IR")
        {
            int x,k;
            cin>>k>>x;
            insert(k+1,x);
        }
        else if(op=="D"){
            int k;
            cin>>k;
            remove(k+1);
        }
    }
    for(int i=Re[0];i!=1;i=Re[i])cout<<e[i]<<" ";
}