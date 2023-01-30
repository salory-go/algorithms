#include <cstring>
#include <iostream>

using namespace std;

const int N = 2e5+3;
const int null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
    int k = (x%N+N)%N;
    while(h[k]!=null&&h[k]!=x)
    {
        k++;
        if(k==N)k=0;
    }
    return k;
}

int main(){
    int n,x;
    cin>>n;
    string op;
    
    memset(h,null,sizeof h);
    
    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I") {
            h[find(x)]=x;
        } else {
            if (h[find(x)]==null) {
                puts("No");
            } else {
                puts("Yes");
            }
        }
    }
    return 0;
}