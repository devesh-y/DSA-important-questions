//https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651?leftPanelTab=0
#include<bits/stdc++.h>
int solve(int n, int x, int y,int z)
{
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;
    int arr[3]={x,y,z};
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i-arr[j]>=0 && dp[i-arr[j]]>=0)
            {
                dp[i]=max(dp[i],dp[i-arr[j]]+1);
            }
        }
     }
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) 
{  
	int ans= solve(n,x,y,z);
    return ans<0? 0: ans;
}