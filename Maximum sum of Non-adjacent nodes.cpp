//https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node *&root){
        
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);

        pair<int,int> ans;
        ans.first=root->data +left.second+right.second;
        ans.second=max(left.first,left.second)+max(right.first,right.second);
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);//include,exclude
    }
};