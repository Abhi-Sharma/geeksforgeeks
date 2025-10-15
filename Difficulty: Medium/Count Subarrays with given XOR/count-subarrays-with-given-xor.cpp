class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long long n = arr.size();
        map<long,long> mpp;
        long long xr = 0;
        mpp[xr]++;
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            xr = xr ^ arr[i];
            
            int x = xr ^ k;
            cnt += mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};