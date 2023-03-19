//here bst size means the number of nodes here
class n
{
    public:
    int size;
    int maxi;
    int mini;
    bool isbst;
};
class Solution
{
    public:
    n solve(Node * root,int &ans)
    {
        if(!root){
            return {0,INT_MIN,INT_MAX,true};
        }
        n left=solve(root->left,ans);
        n right=solve(root->right,ans);
        
        n currnode;
        currnode.size=left.size+right.size+1;
        currnode.maxi=max(root->data,right.maxi);
        currnode.mini=min(root->data,left.mini);
        
        if(left.isbst && right.isbst && (root->data>left.maxi && root->data<right.mini)){
            currnode.isbst=true;
        }
        else{
            currnode.isbst=false ;
        }
        if(currnode.isbst){
            ans=max(ans,currnode.size);
            
        }
     
            return currnode;
        
    }
    int largestBst(Node *root)
    {
    	int ans=0;
    	n temp=solve(root,ans);
    	return ans;
    }
};