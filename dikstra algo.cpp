//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        set<pair<int,int>> s; //distance, to node from src
        
        s.insert({0,S});
        while(!s.empty())
        {
            pair<int,int> temp=*s.begin();
            s.erase(s.begin());
            int distance=temp.first;
            int node=temp.second;
            for(auto neig: adj[node])
            {
                if(distance+ neig[1]<dist[neig[0]])
                {
                    auto record=s.find({dist[neig[0]],neig[0]});
                
                    if(record!=s.end()){
                        s.erase(record);
                    }
                    dist[neig[0]]=distance+ neig[1];
                    s.insert({dist[neig[0]],neig[0]});
                }
            }
        }
        return dist;
    }