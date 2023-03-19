// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]


//using dp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector <vector <vector <int>>> dp(target+1);
        dp[0]={{}};
        for(int i:candidates)
        {
            for(int j=i;j<=target;j++)
            {
                for(auto v:dp[j-i])
                {
                    v.push_back(i);
                    dp[j].push_back(v);
                }
            }
        }
        return dp[target];
	}
};


//backtracking -------sabse fast hai ye
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		//sorting not needed but used for pruning
        sort(begin(candidates),end(candidates));
        int n=candidates.size();
		//removing not possible elements
        while(n&&(candidates[n-1]>target)){n--;}
        int sum=target;
        vector<vector<int>> result;
        vector<int> comb;
        findNextComboSum(candidates,result,comb,n,sum,0);
        return result;
    }
    //Function used to calculate the next possible combination until end of the possible candidates
    void findNextComboSum(vector<int>& candidates,vector<vector<int>>& res,
                         vector<int>& comb,int& n,int sum,int start){
        if(sum<0)return;
        if(sum==0)res.push_back(comb);
        for(int i=start;i<n;i++){
            comb.push_back(candidates[i]);
            findNextComboSum(candidates,res,comb,n,sum-candidates[i],i);
            comb.pop_back();
        }
    }
};