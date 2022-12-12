#include<cstdio>
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int minDistance(int a, int b,int tree[5][5]) {
    return tree[b-1][a];
}

int Mfunction(int a,int b,int tree[5][5],int new_tree[6],int n=6){
    int result=0;
    result = minDistance(a,b,tree)-(new_tree[a]+new_tree[b])/(n-2);
    return result;
}

int newminDistance(int a,int b,int c,int tree[5][5]){
    int result=0;
    result = (minDistance(a,c,tree)+minDistance(b,c,tree)-minDistance(a,b,tree))/2;
    return result;
}

int main(){
    //   A  B   C   D   E
  // B  110 0   0   0   0
  // C  120 117 0   0   0
  // D  117 127 124 0   0
  // E  115 121 125 126 0
  // F  124 121 134 130 123
    int tree[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            tree[i][j] =0;
        }
    }
    tree[0][0]=110;
    tree[1][0]=120;
    tree[2][0]=117;
    tree[3][0]=115;
    tree[4][0]=124;

    tree[1][1]=117;
    tree[2][1]=127;
    tree[3][1]=121;
    tree[4][1]=121;

    tree[2][2]=124;
    tree[3][2]=125;
    tree[4][2]=134;

    tree[3][3]=126;
    tree[4][3]=130;

    tree[4][4]=123;


// 1
    int new_tree[6];
    for(int i=0;i<6;i++){
        new_tree[i]=0;
    }
    int index=0;
    for(int i=0;i<6;i++){
        int sum=0;
        for(int m=0;m<i+1;m++){
            if(i==5){
                if(m==i){
                    break;
                }
                sum+=tree[i-1][m];
            }else{
                sum+=tree[i][m];
            }
        }
        
        for(int j=i+1;j<5;j++){
            sum+=tree[j][i];
        }
        new_tree[index]=sum;
        index++;
    }
    for(int i=0;i<6;i++){
        cout<<new_tree[i]<<endl;
    }

    // 2

    int new_2tree[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            new_2tree[i][j] =0;
        }
    }   
    for(int i=1,m=0;i<6;i++,m++){
        for(int j=0,n=0;j<i;j++,n++){
            new_2tree[m][n] = Mfunction(j,i,tree,new_tree);
            // cout<<i<<" "<<j<<endl;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<new_2tree[i][j]<<" ";
        }
        cout<<endl;
    }
    // 
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            tree[i][j] =0;
        }
    }
    tree[0][0]=123;
    tree[1][0]=115;
    tree[2][0]=121;
    tree[3][0]=125;
    tree[4][0]=126;

    tree[1][1]=124;
    tree[2][1]=121;
    tree[3][1]=134;
    tree[4][1]=130;

    tree[2][2]=110;
    tree[3][2]=120;
    tree[4][2]=117;

    tree[3][3]=117;
    tree[4][3]=127;

    tree[4][4]=124;


// 3
int last_tree[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            last_tree[i][j] =0;
        }
    }
    for(int i=2,m=1;i<6;i++,m++){
        for(int j=2,n=1;j<i+1;j++,n++){
            last_tree[m][n] = tree[i][j];
        }
    }
    for(int i=0,index=2;i<4;i++,index++){
        last_tree[i][0] =newminDistance(0,1,index,tree);
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<last_tree[i][j]<<" ";
        }
        cout<<endl;
    }
    
}