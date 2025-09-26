class Solution {
    private:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] == 0){
                if(dfs(it,vis,adj) == true) return true;
            }
            else if(vis[it] == 1) return true;
        }
        vis[node] = 2;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
       vector<int> vis(V,0);
       vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
       for(int i = 0; i < V; i++){
           if(vis[i] == 0){
               if(dfs(i,vis,adj) == true) return true;
           }
       }
       return false;
        
    }
};