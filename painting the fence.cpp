// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?leftPanelTab=0

int solve(int n ,int k )
{
    vector<int> dp(n+1);
    dp[1]=k;
    dp[2]=k*k;
     for(int i=3;i<=n;i++)
     {
         dp[i]=dp[i-1]*(k-1)+dp[i-2]*(k-1);
     }
    return dp[n];
}

int numberOfWays(int n, int k) 
{
    return solve(n,k);
}