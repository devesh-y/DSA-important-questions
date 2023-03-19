//https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=1
#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	vector<vector<int>>adj(n+1);
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    vector<int>  parent(n+1,-1);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int num=q.front();
        q.pop();
        for(int temp: adj[num]){
            if(!visited[temp]){
                q.push(temp);
                visited[temp]=true;
                parent[temp]=num;
            }
        }
    }
    vector<int> ans;
    int curr=t;
    ans.push_back(t);
    while(curr!=s){
        curr=parent[curr];
        ans.push_back(curr);
    }

    reverse(ans.begin(),ans.end());
	return ans;
}