//https://www.codingninjas.com/codestudio/prob
lems/cut-into-segments_1214651?leftPanelTab=0

#include<bits/stdc++.h>
int solve(int n, int x, int y,int z,vector<int> &dp)
{
    if(n<0){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int a=solve(n-x,x,y,z,dp)+1;
    int b=solve(n-y,x,y,z,dp)+1;
    int c=solve(n-z,x,y,z,dp)+1;
    
    dp[n]= max(a,max(b,c));
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n+1,-1);
	int ans= solve(n,x,y,z,dp);
    return ans<0? 0: ans;
}
