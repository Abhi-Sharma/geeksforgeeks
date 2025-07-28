class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
       int V = adj.size();  // Number of vertices
        vector<int> vis(V, 0); 
       vector<int> ls;
       int start = 0;
       dfs(start,adj,vis,ls);
        return ls;
    }
    private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls ){
        vis[node] = 1;
        ls.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it])
            dfs(it,adj,vis,ls);
        }
    }
};