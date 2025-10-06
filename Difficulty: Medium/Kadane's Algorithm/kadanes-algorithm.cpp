class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
       int n = arr.size();
       int sum = 0;
       int maxSum = arr[0];
       for(int i = 0; i < n; i++){
           sum += arr[i];
           maxSum = max(maxSum, sum);
           if(sum < 0) sum = 0;
       }
        return maxSum;
    }
};