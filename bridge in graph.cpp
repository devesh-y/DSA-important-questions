//https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:
    int timer=0;
    unordered_map<int, list<int>> adj;
    
    
    unordered_map<int,bool> visited;
    vector<vector<int>> result;
    
    void dfs(int node,int parent,vector<int> &discovery,vector<int>& low)
    {
        visited[node]=true;
        discovery[node]=low[node]=timer++;
        
        for(auto neigh: adj[node]){
            if(neigh==parent){
                continue;
            }
            if(!visited[neigh]){
                dfs(neigh,node,discovery,low);
                low[node]=min(low[node],low[neigh]);
                //check edge is bridge
                if(low[neigh]>discovery[node])
                {
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(neigh);
                    result.push_back(ans);
                }
            }
            else{
                //backedge
                low[node]=min(low[node],discovery[neigh]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);        
        }
        vector<int> discovery(n,-1);
        vector<int> low(n,-1);
        int parent=-1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,parent,discovery,low);
            }
        }
        return result;
    }
};