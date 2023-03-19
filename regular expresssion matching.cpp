class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int m=s.size();
        int n=p.size();
        bool dp[m+1][n+1];
        dp[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=false;
        }
        for(int i=1;i<=n;i++)
        {
            if(p[i-1]=='*')
            {
                dp[0][i]=dp[0][i-2];
            }
            else{
                dp[0][i]=false;
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    if(dp[i][j-2])
                    {
                        dp[i][j]=true;
                    }
                    else if(p[j-2]==s[i-1] || p[j-2]=='.')
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else{
                        dp[i][j]=false;
                        }
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[m][n];
    }
};

/*

 | |a|.|*
 |T|F|F|F 
a|F|T|F|T 
b|F|F|T|T 
c|T|F|F|F 


*/