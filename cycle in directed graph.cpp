//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

//dfs
class Solution {
    unordered_map<int,bool> visited;
    unordered_map<int,bool> indfs;
  public:
    bool dfs(int num,vector<int> adj[])
    {
        visited[num]=true;
        indfs[num]=true;
        for(int temp: adj[num])
        {
            if(!visited[temp])
            {
                bool check=dfs(temp,adj);
                if(check==true){
                    return true;
                }
            }
            else if(indfs[temp] )
            {
                return true;
            }
            
            
        }
        indfs[num]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                    
                bool iscycle=dfs(i,adj);
                if(iscycle){
                    return true;
                }
            }
            
        }
        return false;
    }
};



//bfs     using kahn algo    --which is used for directed acyclic graph
//so if kahn work here that means no cycle

class Solution {
    private:
        unordered_map<int,int> indegree; 
  public:
    bool isCyclic(int V, vector<int> adj[]) 
    {
        for(int i=0;i<V;i++){
    	        for(int temp: adj[i]){
    	            indegree[temp]++;
    	        }
    	    }
    	    queue<int> q;
    	    for(int i=0;i<V;i++){
    	        if(indegree[i]==0){
    	            q.push(i);
    	        }
    	    }
    	    int count=0;
   
    	    while(!q.empty())
    	    {
    	        int temp=q.front();
    	        q.pop();
    	        count++;
    	        for(int num: adj[temp])
    	        {
    	            indegree[num]--;
    	            if(indegree[num]==0){
    	                q.push(num);
    	            }
    	        }
    	    }
    	    if(count==V){// if all vertices traversed that means cycle not present
    	        return false;
    	    }
    	    return true;
    }
};
