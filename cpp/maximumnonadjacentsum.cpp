#include<iostream>
#include<vector>
using namespace std;

// Bottom up approch
int maxSubsetSumNoAdjacent(vector<int> array){
  
  int n = array.size();
  vector<int> dp(n+1,0);


  // corner case
  if(array.size()==1){
  	return max(array[0],0);

  }
  else if(n==2){
  	return max(0,max(array[0],array[1]));
  }

  // Bottom up logic
 dp[0] = max(array[0],0);
 dp[1] = max(0,max(array[0],array[1]));

for(int i=2;i<n;i++){
	int inc = array[i] + dp[i-2];
	int exc = dp[i-1];
	dp[i] = max(inc,exc);
}

return dp[n-1];




}

int main(){

	vector<int> arr({6,10,12,7,9,14});
	cout<<maxSubsetSumNoAdjacent(arr);
	return 0;


}