#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        unordered_map<int,bool> visited;
        stack<int> s;
        unordered_map<int ,list<pair<int,int>>> adj;
        
        void addedge(int u,int v,int weight){
            pair<int,int> p= {v,weight};
            adj[u].push_back(p);
        }

        void print(){
            for(auto i: adj){
                cout<<i.first<<" -> ";
                for(auto j: i.second){
                    cout<<"("<<j.first<<","<<j.second<<"), ";

                }
                cout<<"\n";
            }
        }

        void dfs(int node){
            visited[node]=true;

            for(auto temp: adj[node])
            {
                if(!visited[temp.first])
                {
                    dfs(temp.first);
                }
            }
            s.push(node);
        }

        void getshortestpath(int node,vector<int> &distance)
        {
            while(!s.empty())
            {
                int top=s.top();
                s.pop();
                if(distance[top]!=INT_MAX)
                {
                    for(auto i: adj[top])
                    {
                        if(distance[top]+i.second<distance[i.first])
                        {
                            distance[i.first]=distance[top]+i.second;
                        }
                    }
                }
            }
        }
};
signed main()
{
    graph g;
    g.addedge(0,1,5);
    g.addedge(0,2,3);
    g.addedge(1,2,2);
    g.addedge(1,3,6);
    g.addedge(2,3,7);
    g.addedge(2,4,4);
    g.addedge(2,5,2);
    g.addedge(3,4,-1);
    g.addedge(4,5,-2);
    g.print();

    int n=6;

    //toposort 
    for(int i=0;i<n;i++){
        if(!g.visited[i]){
            g.dfs(i);
        }
    }
    int src=1;
    vector<int> distance(n);
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
    }
    distance[src]=0;
    g.getshortestpath(src,distance);


    cout<<"\n\nshortest distances are   \n";
    for(int i=0;i<distance.size();i++){
        cout<<distance[i]<<" ";
    }
    cout<<"\n";
    return 0;
} 