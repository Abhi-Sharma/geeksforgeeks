class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
       int n = arr.size();
       int low = 0;
       int high = n - 1;
       int index = n;
       while(low <= high){
           int mid = (low + high)/2;
           
           if(arr[mid] >= k){
               index = mid;
               high = mid - 1;
           }
           else low = mid + 1;
       }
        return index;
    }
};