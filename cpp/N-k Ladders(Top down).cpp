#include<iostream>
#include<vector>
using namespace std;

/*Approaches
1-Recursive
2-Top down
3-Botton Up
4-Bottom Up optimised Recurrence
*/

//O(K^n)
int countWays(int n,int k){
if(n==0){
	return 1;

}
if(n<0){
	return 0;
}
// recursive case
int ans=0;
for(int i=1; i<=k;i++){
	ans += countWays(n-i,k);
}
return ans;

}


// Top Down code (O(n,k))
int countWaysTD(int n,int k,int *dp){
if(n==0){
	return 1;

}
if(n<0){
	return 0;
}
//check if state is already computed
if(dp[n]!=0){
	return dp[n];
}
int ans=0;
for(int i=1; i<=k;i++){
	ans += countWaysTD(n-i,k,dp);
}
return dp[n]=ans;

}

// Bottom Up approach(O(n*k))

int countWaysBu(int n,int k){
	// iteratice approch

	vector<int> dp(n+1,0);

	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				dp[i] += dp[i-j];
			}
		}
	}
	return dp[n];

}
// Bottom Up-optimize (O(n+k))
int countWaysOpt(int n,int k)
{
	vector<int> dp(n+1,0);

	dp[0] = dp[1] = 1;

	for(int i=2;i<=k;i++){
		dp[i] = 2*dp[i-1];

	}
	return dp[n];
}

int main(){
	int n,k;
	cin>>n>>k;
	int dp[1000] = {0};
	cout<<countWaysTD(n,k,dp)<<endl;
	cout<<countWaysOpt(n,k)<<endl;
	return 0;
}