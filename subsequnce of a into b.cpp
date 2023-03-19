#include<bits/stdc++.h>
using namespace std;
#define int long long int
int solve(string s,string t,int i,int j,string temp,vector<vector<int>> &dp)
{
    if(temp==t){
        return 1;
    }
    // if(i==s.size() && j==t.size()){
    //     return 1;
    // }
    else if(i==s.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int count=0;
    if(j<t.size() && s[i]==t[j]){
        temp+=s[i];
        count+=solve(s,t,i+1,j+1,temp,dp);
        temp.pop_back();
    }
    count+=solve(s,t,i+1,j,temp,dp);
    dp[i][j]=count;
    return dp[i][j];
}
signed main()
{
    string s="abcaababccc";
    string t="abc";
    string temp="";
    vector<vector<int>> dp(s.size()+1,vector<int> (t.size()+1,-1));
    int ans =solve(s,t,0,0,temp,dp);
    cout<<ans;
    return 0;
}