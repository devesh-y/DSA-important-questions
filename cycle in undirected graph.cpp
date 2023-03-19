//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//bfs
class Solution {
    private:
        unordered_map<int, bool> visited;
        unordered_map<int,int> parentof;
  public:

    bool bfs(int num,vector<int> adj[])
    {
        visited[num]=true;
        parentof[num]=-1;
        queue<int> q;
        q.push(num);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(int i=0;i<adj[temp].size();i++)
            {
                if(visited[adj[temp][i]] && parentof[temp]!=adj[temp][i])
                {
                    return true;
                }
                else if(!visited[adj[temp][i]]){
                    visited[adj[temp][i]]=true;
                    parentof[adj[temp][i]]=temp;
                    q.push(adj[temp][i]);
                }
                
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        for(int i=0;i<V;i++)
        {
             if(!visited[i]){
                bool iscycle=bfs(i,adj);
                if(iscycle==true)
                {
                     return true;
                }
            }    
        }
        return false;
    }
};

//dfs
class Solution {
    private:
        unordered_map<int, bool> visited;
  public:

    bool dfs(int num,int parent,vector<int> adj[])
    {
        visited[num]=true;
        for(int i=0;i<adj[num].size();i++)
        {
            if(!visited[adj[num][i]])
            {
                
                bool check=dfs(adj[num][i],num,adj);
                if(check==true){
                    return true;
                }
            }
            else if(adj[num][i]!=parent){
                return true;
            }
             
            
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        for(int i=0;i<V;i++){
             
             if(!visited[i])
             {
        
                bool iscycle=dfs(i,-1,adj);
                if(iscycle==true)
                {
                     return true;
                }
             }
             
        }
        return false;
        
        
    }
};