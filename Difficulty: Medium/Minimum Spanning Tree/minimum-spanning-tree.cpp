class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
       vector<vector<pair<int,int>>> adj(V);
       for(auto it : edges){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       }
       
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int> vis(V,0);
       pq.push({0,0});
       int sum = 0;
       while(!pq.empty()){
           int dis = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           
           if(vis[node] == 1) continue;
           vis[node] = 1;
           sum += dis;
           for(auto it : adj[node]){
               int edW = it.second;
               int adjNode = it.first;
               if(!vis[adjNode]){
                   pq.push({edW,adjNode});
               }
           }
       }
       return sum;
        
    }
};