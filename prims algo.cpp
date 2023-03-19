//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,INT_MAX);
        vector<bool> inmst(V,false);
        vector<int> parent(V,-1);
        
        int ans=0;
        int src=0;
        key[src]=0;
        for(int i=0;i<V-1;i++){
            int mini=INT_MAX; 
            int u;
            for(int v=0;v<V;v++){
                if(inmst[v]==false  && key[v]<mini){
                    u=v;
                    mini=key[v];
                }
            }
            inmst[u]=true;
            for(auto it: adj[u]){
                int v=it[0];
                int w=it[1];
                if(inmst[v]==false && w<key[v]){
                    parent[v]=u;
                    key[v]=w;
                   
                }
            }
        }
        for(int i=0;i<V;i++){
            ans+=key[i];
        }
        return ans;
 
    }
};

//using priority queue


#define pp pair<int,int>  //weight , from
class Solution
{
	public:

    int spanningTree(int V, vector<vector<int>> adj[])
    {
      
        vector<int> key(V,INT_MAX);

        vector<bool> inmst(V,false);
     
        priority_queue<pp,vector<pp> ,greater<pp>> q;
        int ans=0;
        int src=0;
        key[src]=0;
        q.push({0,0});
        
        while(!q.empty()){
            auto u=q.top();
            q.pop();
            if(inmst[u.second]==true){
                continue;
            }
            inmst[u.second]=true;
            for(auto x: adj[u.second]){
                int v = x[0];
                int weight = x[1];
                if (inmst[v] == false && weight< key[v] )
                {
                    key[v] = weight;
                    q.push({key[v],v});
                }
            }
        }
  

        for(int i=1;i<V;i++){
            ans+=key[i];
        }
        
        return ans;
        
        
    }
};