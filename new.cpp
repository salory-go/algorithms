#include<iostream>
#include<cstring>
using namespace std;
int dp[105][105];
int min(int a, int b, int c){
	if(a < b){
		if(a < c)return a;
		return c;
	}
	if(b < c)return b;
	return c;
}
int main(){
	string s1, s2;
	s1 ="ATGGAGAAAA TAGAGCTTCT TCTTGCAATA GTCAGTCTTG TCAAAAGTGA TCAGATTTGC ATTGGTTACC ATGCAAACAA CTCGACAGAG CAGGTTGACA CAATAATGGA AAAGAACGTT ACTGTTACAC ATGCCCAAGA CATACTGGAA AAGACACACA ACGGGAAGCT CTGCGATCTA AATGGAGTAA AGCCTCTCAT";
	s2 ="ATGGAGAAAA TAGTGCTTCT TCTTGCAATA GTCAGTCTTG TTAAAAGTGA TCAGATTTGC ATTGGTTACC ATGCAAACAA CTCGACAGAG CAGGTTGACA CAATAATGGA AAAGAACGTT ACTGTTACAC ATGCCCAAGA CATACTGGAA AAGACACACA ACGGGAAGCT CTGCGATCTA GATGGAGTGA AGCCTCTAAT";
	int lena, lenb;
	lena = s1.length();//可用s1.size()代替，注意导入cstring库
	lenb = s2.length();
	if(s1[0] == s2[0]){
		dp[0][0] = 0;
	} else {
		dp[0][0] = 1;
	}
	for(int i = 0; i < lenb; i++){
		dp[0][i] = i;
	}
	for(int i = 0; i < lena; i++){
		dp[i][0] = i;
	}
	for(int i = 1; i < lena; i++){
		for(int j = 1; j < lena; j++){
			if(s1[i] == s2[j]){
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
			}
		}
	}
	cout << dp[lena][lenb];
	return 0;
}
