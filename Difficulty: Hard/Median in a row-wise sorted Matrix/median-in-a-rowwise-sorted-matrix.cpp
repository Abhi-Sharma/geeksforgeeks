class Solution {
    int upperbound(vector<int> arr, int n, int m, int x){
        int low = 0;
        int high = m - 1;
        int ans = m;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int counter(vector<vector<int>> &mat, int n, int m, int mid){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += upperbound(mat[i],n,m,mid);
        }
        return cnt;
    }
  public:
    int median(vector<vector<int>> &mat) {
       int n = mat.size();
       int m = mat[0].size();
       
       int mini = INT_MAX;
       int maxi = INT_MIN;
       for(int i = 0; i < n; i++){
           mini = min(mini, mat[i][0]);
           maxi = max(maxi, mat[i][m-1]);
       }
       
       int low = mini;
       int high = maxi;
       while(low <= high){
           int mid = (low + high)/2;
           int req = (n*m)/2;
           int smallCount = counter(mat,n,m,mid);
           if(smallCount <= req){
               low = mid + 1;
           } 
           else high = mid - 1;
       }
       return low;
    }
};
