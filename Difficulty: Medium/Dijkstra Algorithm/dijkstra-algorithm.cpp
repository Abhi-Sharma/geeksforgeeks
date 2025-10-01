// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            int  u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<int> dist(V,1e9);
        dist[src] = 0;
        
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(dist[node] + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dist[node] + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};