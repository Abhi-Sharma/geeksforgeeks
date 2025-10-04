
class Solution {
  public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X) {
        
        queue<pair<int,int>> q;
        vector<int> vis(V,0);
        vis[0] = 1;
        q.push({0,0});
        while(!q.empty()){
            int node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(node == X) return level;
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,level+1});
                }
            }
        }
        return -1;
    }
};