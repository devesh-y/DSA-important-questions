//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/the-stock-market-f51a84fd/

#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(int index,int tempk,int changesubarray,int n,int k,vector<int> &arr, vector<vector<vector<int>>> &dp  ){
    if(index==n){
        if( changesubarray && tempk==k+1){
            return 0;
        }
        else{
            return INT_MIN;
        }
    }
    if(tempk>k ){
        return INT_MIN;
    }
    if(dp[index][tempk][changesubarray]!=-1 ){
        return dp[index][tempk][changesubarray];
    }
  
    int ans=0;
    if(tempk&1){
        ans=-arr[index]+ max( func(index+1, tempk, 0,n,k,arr,dp), func(index+1,tempk+1,1,n,k,arr,dp) ) ;
    }
    else{
        ans=arr[index]+max( func(index+1, tempk, 0,n,k,arr,dp), func(index+1,tempk+1,1,n,k,arr,dp) ) ;
    }
    dp[index][tempk][changesubarray]=ans;
    return ans;

}
signed main()
{
    int n;
    cin>>n;
    vector<int> arr(n+2);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k=0;
    cin>>k;
    vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(k+2, vector<int>(2,-1)  ) );
    int ans=func(0,1,0, n,k,arr, dp);
    cout<<ans;



}