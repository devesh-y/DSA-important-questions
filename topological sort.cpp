//https://practice.geeksforgeeks.org/problems/topological-sort/1


//dfs

class Solution
{
    private:
        stack<int> s;
        unordered_map<int,bool> visited;
	public:
	    void solve(int num,vector<int> adj[]){
	        visited[num]=true;

	        for(int temp: adj[num]){
	            if(!visited[temp]){
	                solve(temp,adj);
	            }
	        }
	        s.push(num);
	    }
    	vector<int> topoSort(int V, vector<int> adj[]) 
    	{
    	   for(int i=0;i<V;i++)
    	   {
    	       if(!visited[i]){
    	           solve(i,adj);
    	       }
    	       
    	   }
    	   vector<int> ans;
    	  while(!s.empty()){
    	      ans.push_back(s.top());
    	      s.pop();
    	  }
    	  return ans;
    	}
    	
};

//bfs            kahn's algo ---used in directed acyclic graph

class Solution
{
    private:
        unordered_map<int,int> indegree; 
	public:
    	vector<int> topoSort(int V, vector<int> adj[]) 
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
    	    vector<int> ans;
    	    while(!q.empty()){
    	        int temp=q.front();
    	        q.pop();
    	        ans.push_back(temp);
    	        for(int num: adj[temp])
    	        {
    	            indegree[num]--;
    	            if(indegree[num]==0){
    	                q.push(num);
    	            }
    	        }
    	    }
    	    return ans;
    	  
    	}
    	
};
