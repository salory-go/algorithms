#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;

int q[N],head=-1;

string empty()
{
    if(head == -1)return "YES";
    else return "NO";
}

void push(int x)
{
    q[++head] = x;
}

void pop()
{
    head--;
}

int query()
{
   return q[head]; 
}

int main(){
    int n;
    cin>>n;
    while(n--){
        string op;
        
        cin>>op;
        if(op=="push")
        {
            int x;
            cin>>x;
            push(x);
        }
        else if(op=="empty")cout<<empty()<<endl;
        else if(op=="pop")pop();
        else cout<<query()<<endl;
    }
    
}