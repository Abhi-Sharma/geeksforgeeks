// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        queue<pair<int,int>> q;
        vector<int> dist(100000,1e9);
        dist[start] = 0;
        q.push({0,start});
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto it : arr){
                int num = (node * it) % 100000;
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if(num == end) return steps + 1;
                    q.push({steps + 1, num});
                }
            }
        }
        return -1;
    }
};
