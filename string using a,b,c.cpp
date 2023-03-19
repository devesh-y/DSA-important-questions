//the atmost values are b=1 and c=2 in a string 
//with a,b,c
//find how many possible strings

#include<bits/stdc++.h>
using namespace std;

int solve(int n, int b, int c,vector<vector<vector<int>>>& dp)
{
	if (b < 0 || c < 0) 
        return 0;
	if (n == 0) 
        return 1;
	if (b == 0 && c == 0) 
        return 1;
	if(dp[n][b][c]!=-1){
		return dp[n][b][c];
	}
	int res = solve(n-1, b, c,dp)+solve(n-1, b-1, c,dp)+solve(n-1, b, c-1,dp);
	dp[n][b][c]=res;
	return res;
}


int main()
{
	int n = 7; 
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    int ans=solve(n, 1, 2,dp);
	
    cout<<ans;
	return 0;
}
