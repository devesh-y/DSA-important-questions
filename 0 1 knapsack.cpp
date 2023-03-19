//https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0


//by recursion  + memorisation
int solve(vector<int> &w,vector<int> &v,int index,int m,vector<vector<int>> &dp)
{
    if(index==0){
        if(w[0]<=m){
            return v[0];
        }
        else{
            return 0;
        }
    }
    if(dp[index][m]!=-1){
        return dp[index][m];
    }
    int include=0;
    if(w[index]<=m){
        include=solve(w,v,index-1,m-w[index],dp)+v[index];
       }
    int exclude=solve(w,v,index-1,m,dp);
    dp[index][m]=max(include,exclude);
    return dp[index][m];

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}


//by tabulation 
int solve(vector<int> &w,vector<int> &v,int n,int m)
{
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    for(int i=0;i<=m;i++)
    {
        if(w[0]<=i){
            dp[0][i]=v[0];
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            int include=0;
            if(w[i]<=j)
            {
                include=dp[i-1][j-w[i]]+v[i];
            }
            int exclude=dp[i-1][j];
            dp[i][j]=max(include,exclude);
         }
    }
    
    return dp[n-1][m];

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	return solve(weight,value,n,maxWeight);
}



//by recursion 
int solve(vector<int> &w,vector<int> &v,int index,int m)
{
    if(index==0){
        if(w[0]<=m){
            return v[0];
        }
        else{
            return 0;
        }
    }
    int include=0;
    if(w[index]<=m){
        include=solve(w,v,index-1,m-w[index])+v[index];
       }
    int exclude=solve(w,v,index-1,m);
    return max(include,exclude);

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return solve(weight,value,n-1,maxWeight);
}