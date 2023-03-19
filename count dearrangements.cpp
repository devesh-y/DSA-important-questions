//https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/

#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
	vector<int> dp(n+1);
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; ++i)
    {
		dp[i] = (i - 1) * (dp[i - 1] +dp[i - 2]);
    }
	return dp[n];
}

// Driver code
int main()
{
	int n = 4;
	cout<<solve(n);
	return 0;
}
