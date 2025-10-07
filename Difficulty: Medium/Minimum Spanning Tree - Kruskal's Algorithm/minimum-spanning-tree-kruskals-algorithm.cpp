// User function Template for C++
class Disjointset{
    public:
    vector<int> parent, size;
    Disjointset(int n){
    parent.resize(n+1);
    size.resize(n+1);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int findUPar(int node){
    if(node == parent[node]) return node;
    return parent[node] = findUPar(parent[node]);
}

void UnionbySize(int u, int v){
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    
    if(ulp_v == ulp_u) return;
    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
    else{
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}  
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });
    Disjointset ds(V);
    int mstW = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstW += w;
                ds.UnionbySize(u,v);
            }
        }
        return mstW;
    }
};