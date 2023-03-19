//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution
{
	public:
	static bool comp(vector<int> &a,vector<int> &b){
	    return a[2]<b[2];
	}
    int findparent(vector<int> &parent,int node){
        if(parent[node]==node){
            return node;
        }
        parent[node]=findparent(parent,parent[node]);
        return parent[node];
    }
    void unionset(int u,int v, vector<int> &parent,vector<int> &rank)
    {
        u=findparent(parent,u);
        v=findparent(parent,v);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(it[0]);
                temp.push_back(it[1]);
                edges.push_back(temp);
            }
        }
        sort(edges.begin(),edges.end(),comp);
        vector<int> parent(V);
        vector<int> rank(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
        int minweight=0;
        
        for(int i=0;i<edges.size();i++){
            int u=findparent(parent,edges[i][0]);
            int v=findparent(parent,edges[i][1]);
            int wt=edges[i][2];
            if(u!=v){
                minweight+=wt;
                unionset(u,v,parent,rank);
            }
        }
        return minweight;
    }
};
int main(){

}