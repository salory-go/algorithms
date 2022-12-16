#include<cstdio>
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int minDistance(int a, int b,int tree[2][2]) {
    return tree[b-1][a];
}
int Mfunction(int a,int b,int tree[2][2],int new_tree[6],int n=6){
    int result=0;
    result = minDistance(a,b,tree)-(new_tree[a]+new_tree[b])/(n-2);
    return result;
}
int newminDistance(int a,int b,int c,int tree[2][2]){
    int result=0;
    result = (minDistance(a,c,tree)+minDistance(b,c,tree)-minDistance(a,b,tree))/2;
    return result;
}

int main(){
// 63 0
// 67 124
    int tree[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            tree[i][j] =0;
        }
    }
    tree[0][0]=63;
    tree[1][0]=67;

    tree[1][1]=124;

// 1
   int new_tree[3];
    for(int i=0;i<3;i++){
        new_tree[i]=0;
    }
    int index=0;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int m=0;m<i+1;m++){
            if(i==2){
                if(m==i){
                    break;
                }
                sum+=tree[i-1][m];
            }else{
                sum+=tree[i][m];
            }
        }
        for(int j=i+1;j<2;j++){
            sum+=tree[j][i];
        }
        new_tree[index]=sum;
        index++;
    }
    for(int i=0;i<3;i++){
        cout<<new_tree[i]<<endl;
    }

    // 2
    int new_2tree[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            new_2tree[i][j] =0;
        }
    }   
    for(int i=1,m=0;i<3;i++,m++){
        for(int j=0,n=0;j<i;j++,n++){
            new_2tree[m][n] = Mfunction(j,i,tree,new_tree);
            // cout<<i<<" "<<j<<endl;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<new_2tree[i][j]<<" ";
        }
        cout<<endl;
    }

    // 3
    int last_tree[1][1];
    for(int i=0;i<1;i++){
        for(int j=0;j<1;j++){
            last_tree[i][j] =0;
        }
    }
    for(int i=2,m=1;i<2;i++,m++){
        for(int j=2,n=1;j<i+1;j++,n++){
            last_tree[m][n] = tree[i][j];
        }
    }
    for(int i=0,index=2;i<1;i++,index++){
        last_tree[i][0] =newminDistance(0,1,index,tree);
    }
    for(int i=0;i<1;i++){
        for(int j=0;j<1;j++){
            cout<<last_tree[i][j]<<" ";
        }
        cout<<endl;
    }
}