#include<iostream>
using namespace std;
const int N = 1e5+10;
int e[N],ne[N],head,idx;

void init()
{
    head=-1;
    idx=0;
}

void insert_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void insert(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void del(int k)
{
    ne[k] = ne[ne[k]];
}

int main(){
    int n;
    cin>>n;
    init();
    while(n--)
    {
        char op[2];
        scanf("%s",&op);
        if(op[0]=='H')
        {
            int x;
            cin>>x;
            insert_head(x);
        }
        else if(op[0]=='I')
        {
            int x,k;
            cin>>k>>x;
            insert(k-1,x);
        }
        else if(op[0]=='D'){
            int k;
            cin>>k;
            if(k==0)head = ne[head];
            del(k-1);
        }
    }
    for(int i=head;i!=-1;i=ne[i])cout<<e[i]<<" ";
}
// idx下标就是第几个插入的数，ne的下标和值都是idx，初始化有head，k要减一，因为idx从1开始
// remove都是一样的，head是-1，最后也是-1