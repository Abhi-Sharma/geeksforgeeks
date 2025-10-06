class Solution {
    int firstPos(vector<int>& arr, int target){
        int n = arr.size();
        int low  = 0;
        int high = n - 1;
        int first = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return first;
    }
    
    int lastPos(vector<int>& arr, int target){
        int n = arr.size();
        int low  = 0;
        int high = n - 1;
        int last = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return last;
    }
    
  public:
    int countFreq(vector<int>& arr, int target) {
        int first = firstPos(arr,target);
        int last = lastPos(arr,target);
        if(first == -1 || last == -1) return 0;
        int cnt = last - first + 1;
        return cnt;
    }
};
