#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 1010,M = 15;

int n,m,f[M][M];
char str[N][M];

int edit_distance(char a[],char b[])
{
    int n = strlen(a+1),m = strlen(b+1);
    for(int i=0;i<=m;i++) f[0][i] = i;
    for(int i=0;i<=n;i++) f[i][0] = i;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j] = min(f[i-1][j]+1,f[i][j-1]+1);
            f[i][j] = min(f[i][j],f[i-1][j-1]+(a[i]!=b[j]));
        }
    }
    return f[n][m];
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>(str[i]+1);
    
    while(m--)
    {
        int res = 0;
        char s[N];
        int limit;
        scanf("%s%d",s + 1,&limit);
        for(int j=0;j<n;j++)
            if(edit_distance(str[j],s)<=limit) res++;
        cout<<res<<endl;
    }
    
    
}
