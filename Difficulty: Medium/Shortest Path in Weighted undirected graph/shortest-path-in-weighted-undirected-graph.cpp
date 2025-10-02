class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
       vector<vector<pair<int,int>>> adj(n+1);
       for(auto it : edges){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       }
       
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       pq.push({0,1});
       vector<int> dist(n+1, 1e9);
       vector<int> parent(n+1);
       dist[1] = 0;
       for(int i = 1; i <= n; i++) parent[i] = i;
       
       while(!pq.empty()){
           int node = pq.top().second;
           int dis = pq.top().first;
           pq.pop();
           for(auto it : adj[node]){
               int edgeWeight = it.second;
               int adjNode = it.first;
               if(dist[node] + edgeWeight < dist[adjNode]){
                   dist[adjNode] = dist[node] + edgeWeight;
                   pq.push({dist[adjNode],adjNode});
                   parent[adjNode] = node;
               }
           }
       }
       if(dist[n] == 1e9) return {-1};
       vector<int> path;
       int node = n;
       while(parent[node] != node){
           path.push_back(node);
           node = parent[node];
       }
       path.push_back(1);
       reverse(path.begin(),path.end());
       vector<int> ans;
        ans.push_back(dist[n]);
        for(int v : path) ans.push_back(v);

        return ans;
    }
};