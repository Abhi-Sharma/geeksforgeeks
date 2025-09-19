// User function Template for C++

class Solution {
  public:
  void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,int V  ){
    vis[node] = 1;
     for(int j = 0; j < V; j++){
            if(adj[node][j] == 1 && !vis[j]){
                dfs(j, adj, vis,V);
            }
}
}
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vis(V,0);
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis,V);
            }
        }
        return cnt;
        
    }
};