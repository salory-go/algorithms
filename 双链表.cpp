#include<iostream>
#include<cstdio>
using namespace std;

const int M = 1e5+10;


int e[M],Le[M],Re[M],head,end,indx;

void init()
{
    Le[1] = 0;
    Re[0] = 1;
    indx = 2;
}
void insert_left(int k,int x)
{
    e[indx] = x;
    Re[indx] = k;
    Le[indx] = Le[k];
    Re[Le[k]] = indx;
    Le[k] = indx++;
}
//! 当然在 K 的左边插入一个数 可以再写一个 ， 也可以直接调用我们这个函数，在 k 的左边插入一个 数 等价于在 l[k] 的右边插入一个数 add(l[k],x)

void insert_right(int k,int x)
{
    e[indx] = x;
    Re[indx] = Re[k];
    Le[indx] = k;
    Le[Re[k]] = indx;
    Re[k] = indx++;
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
    while(n--){
        string c;
        cin>>c;
        if(c=="L")
        {
            int x;
            cin>>x;
            insert_left(Re[0],x);
        }
        else if(c=="R")
        {
            int x;
            cin>>x;
             insert_right(Le[1],x);
        }
        else if(c=="D")
        {
            int k;
            cin>>k;
            remove(k+1);
        }
        else if(c=="IL")
        {
            int k,x;
            cin>>k>>x;
            insert_left(k+1,x);
        }
        else 
        {
            int k,x;
            cin>>k>>x;
            insert_right(k+1,x);
        }
         
        // for(int i=0;i<1;i++)cout<<e[i];
    }
    for(int i=Re[0];i!=1;i = Re[i])cout<<e[i]<<" ";
}