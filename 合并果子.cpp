#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> heap;
    
    int n;
    cin>>n;
    while (n -- )
    {
        int m;
        cin>>m;
        heap.push(m);
    }
    
    int res = 0;
    while (heap.size()!=1)
    {
        int a = heap.top();heap.pop();
        int b = heap.top();heap.pop();
        res += a+b;
        heap.push(a+b);
    }
    
    cout<<res;
}
