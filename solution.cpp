#include<cstdio>
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int dp[105][105];

int minDistance(string word1, string word2) {
	int row = word1.size() + 1;
    int col = word2.size() + 1;
    int dp[row][col];
    //把第一行和第一列初始化
    for(int j = 0; j < col; ++j)
    {
        dp[0][j] = j;
    }
    for(int i = 0; i < row; ++i)
    {
        dp[i][0] = i;
    }
    //依次算出上图每个格子的状态
    for(int i = 1; i < row; ++i)
    {
        for(int j = 1; j < col; ++j)
        {
        	//如果两次字符相等，不需要替换操作
        	//就像上图的由h-->wh
            if(word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
	return dp[row - 1][col - 1];
}

int Mfunction(int a,int b,string HN[7],int new_tree[6],int n=7){
    int result=0;
    result = minDistance(HN[a],HN[b])-(new_tree[a]+new_tree[b])/(n-2);
    return result;
}

int Sfunction1(int a,int b,string HN[7],int new_tree[6],int n=7){
    int result=0;
    result = minDistance(HN[a],HN[b])/2-(new_tree[a]-new_tree[b])/2*(n-2);
    return result;
}
int Sfunction2(int a,int b,string HN[7],int new_tree[6],int n=7){
    int result=0;
    result = minDistance(HN[a],HN[b])-Sfunction1(a,b,HN,new_tree);
    return result;
}

int newminDistance(int a,int b,int c,string HN[7]){
    int result=0;
    result = (minDistance(HN[a],HN[c])+minDistance(HN[b],HN[c])-minDistance(HN[a],HN[b]))/2;
    return result;
}

int main(){
    string H5N2_1 ="ATGGAGAAAA TAGAGCTTCT TCTTGCAATA GTCAGTCTTG TCAAAAGTGA TCAGATTTGC ATTGGTTACC ATGCAAACAA CTCGACAGAG CAGGTTGACA CAATAATGGA AAAGAACGTT ACTGTTACAC ATGCCCAAGA CATACTGGAA AAGACACACA ACGGGAAGCT CTGCGATCTA AATGGAGTAA AGCCTCTCAT ";
    string H5N2_2 ="ATGGAGAAAA TAGTGCTTCT TCTTGCAATA GTCAGTCTTG TTAAAAGTGA TCAGATTTGC ATTGGTTACC ATGCAAACAA CTCGACAGAG CAGGTTGACA CAATAATGGA AAAGAACGTT ACTGTTACAC ATGCCCAAGA CATACTGGAA AAGACACACA ACGGGAAGCT CTGCGATCTA GATGGAGTGA AGCCTCTAAT ";
    string H1N1 =  "ATGGATGTCA ATCCGACTCT ACTTTTCCTA AAAATTCCAG CGCAAAATGC CATAAGCACC ACATTCCCTT ATACTGGAGA TCCTCCATAC AGCCATGGAA CAGGAACAGG ATACACCATG GACACAGTAA ACAGAACACA CCAATACTCA GAAAAGGGAA AGTGGACGAC AAACACAGAG ACTGGTGCAC CCCAGCTCAA ";
    string H2N2 =  "TCAAATATAT TCAATATGGA GAGAATAAAG GAACTAAGAG ACCTAATGTC ACAGTCTCGC ACCCGCGAGA TACTCACAAA AACCACTGTG GACCATATGG CCATAATCAA GAAGTACACA TCAGGGAGAC AAGAGAAGAA CCCTGCACTT AGAATGAAGT GGATGATGGC AATGAAATAT CCAATTACAG CGGACAAGAG ";
    string H3N2 =  "CAAAAACTTC CTGGAAATGA CAATAGCACG GCAACGCTGT GCCTTGGGCA CCATGCAGTA CCAAACGGAA CGATAGTGAA AACAATCACG AATGACCGAA TTGAAGTTAC TAATGCCACT GAGCTGGTTC AGAATTCCTC AATAGGTGAA ATATGCGACA GTCCTCATCA GATCCTTGAT GGAGAAAACT GCACACTAAT ";
    string H7N9 =  "ATGAACACTC AAATCCTGGT ATTCGCTCTG ATTGCGATCA TTCCAACAAA TGCAGACAAA ATCTGCCTCG GACATCATGC CGTGTCAAAC GGAACCAAAG TAAACACATT AACTGAAAGA GGAGTGGAAG TCGTCAATGC AACTGAAACA GTGGAACGAA CAAACACCCC CAGGATCTGC TCAAAAGGGA AAAGGACAGT ";
    string SARS =  "CTACCCAGGA AAAGCCAACC AACCTCGATC TCTTGTAGAT CTGTTCTCTA AACGAACTTT AAAATCTGTG TAGCTGTCGC TCGGCTGCAT GCCTAGTGCA CCTACGCAGT ATAAACAATA ATAAATTTTA CTGTCGTTGA CAAGAAACGA GTAACTCGTC CCTCTTCTGC AGACTGCTTA CGGTTTCGTC CGTGTTGCAG ";
    string HN[7] = {H5N2_1,H5N2_2,H1N1,H2N2,H3N2,H7N9,SARS};
    int tree[6][6];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            tree[i][j] =0;
        }
    }
    for(int i=1,m=0;i<7;i++,m++){
        for(int j=0,n=0;j<i;j++,n++){
            tree[m][n] = minDistance(HN[i],HN[j]);
            // cout<<i<<" "<<j<<endl;
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<tree[i][j]<<" ";
        }
        cout<<endl;
    }


    //1
    int new_tree[7];
    for(int i=0;i<7;i++){
        new_tree[i]=0;
    }
    int index=0;
    for(int i=0;i<7;i++){
        int sum=0;
        for(int m=0;m<i+1;m++){
            if(i==6){
                if(m==i){
                    break;
                }
                sum+=tree[i-1][m];
            }else{
                sum+=tree[i][m];
            }
        }
        
        for(int j=i+1;j<6;j++){
            sum+=tree[j][i];
        }
        new_tree[index]=sum;
        index++;
    }
    for(int i=0;i<7;i++){
        cout<<new_tree[i]<<endl;
    }


    //2
    int new_2tree[6][6];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            new_2tree[i][j] =0;
        }
    }   
    for(int i=1,m=0;i<7;i++,m++){
        for(int j=0,n=0;j<i;j++,n++){
            new_2tree[m][n] = Mfunction(j,i,HN,new_tree);
            // cout<<i<<" "<<j<<endl;
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<new_2tree[i][j]<<" ";
        }
        cout<<endl;
    }

    // 3
    int last_tree[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            last_tree[i][j] =0;
        }
    }
    for(int i=3,m=1;i<7;i++,m++){
        for(int j=2,n=1;j<i;j++,n++){
            last_tree[m][n] = minDistance(HN[i],HN[j]);
            // cout<<i<<" "<<j<<endl;
        }
    }
    for(int i=0,index=2;i<5;i++,index++){
        last_tree[i][0] =newminDistance(0,1,index,HN);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<last_tree[i][j]<<" ";
        }
        cout<<endl;
    }
}