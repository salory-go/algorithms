#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5+10;

int stk[N],head =0;

void push(int x)
{
    stk[++head] = x;
}

void pop()
{
    head--;
}

bool empty()
{
    return head==0;
}

int query()
{
    return stk[head];
}

int main(){
    int n,x;
    cin>>n;
    string op;
    while(n--)
    {
        cin>>op;
        if(op=="push")
        {
            cin>>x;
            push(x);
        }
        else if(op=="pop")
        {
            pop();
        }
        else if(op=="empty")
        {
            if(empty())puts("YES");
            else puts("NO");
        }
        else
        {
            cout<<query()<<endl;
        }
    }
}