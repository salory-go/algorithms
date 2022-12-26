#include<cstdio>
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = q[(l+r)/2];
    while(i<j){
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main(){
    int n=0;
    cin>>n;
    int q[N],i=0;
    while(i<n){
       cin>>q[i++];
    }
    quick_sort(q,0,n-1);
    i=0;
    while(i<n){
       cout<<q[i++];
    }
}
//快速排序和归并排序的递归都是一样，指针间隔指针都相同，只需要其中一个移位。快速排序时，端点值内移，先do后while。
