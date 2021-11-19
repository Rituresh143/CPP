#include<iostream>
#include<vector>
using namespace std;

int lcs(string s1,string s2,int i,int j,vector<vector<int>> &dp){
    // base case
	if(i==s1.length() or j==s2.length()){
		return 0;
	}

	if(dp[i][j]=-1){
		return dp[i][j];
	}

	// rec case
	if(s1[i]==s2[i]){
		return dp[i][j] = 1+lcs(s1,s2,i+1,j+1,dp);
	}

	int op1 = lcs(s1,s2,i+1,j,dp);
	int op2 = lcs(s1,s2,i,j+1,dp);
    return dp[i][j] = max(op1,op2);
}

int main(){

	string s1 = "ABCD";
	string s2 = "ABEDG";

	int n1 = s1.length();
	int n2 = s2.length();

	vector<vector<int> >dp(n1,vector<int>(n2,-1));
 

    cout<<lcs(s1,s2,0,0,dp)<<endl;

    return 0;

}