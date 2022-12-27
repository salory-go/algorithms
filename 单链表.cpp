#include<iostream>
#include<cstdio>
using namespace std;

const int M = 1e5+10;


int e[M],ne[M],head,indx;

void init()
{
    head = -1;
    indx = 0;
}

void add_to_head(int x)
{
    e[indx] = x;
    ne[indx] = head;
    head = indx++;
}

void insert(int k,int x)
{
    e[indx] = x;
    ne[indx] = ne[k];
    ne[k] = indx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main(){
    int n;
    cin>>n;
    init();
    while(n--){
        char c;
        cin>>c;
        if(c=='H')
        {
            int x;
            cin>>x;
            add_to_head(x);
        }
        else if(c=='I')
        {
            int x,k;
            cin>>k>>x;
            insert(k-1,x);
        }
        else if(c=='D')
        {
            int k;
            cin>>k;
            if(k==0)head = ne[head];
            remove(k-1);
        }
    }
    for(int i=head;i!=-1;i = ne[i])cout<<e[i]<<" ";
    
}