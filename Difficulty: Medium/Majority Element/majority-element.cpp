class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int el = 0;
        for(int i = 0; i < n; i++){
            if(cnt == 0){
                cnt++;
                el = arr[i];
            }
            else if(el == arr[i]) cnt++;
            else cnt--;
        }
        
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(el == arr[i]) cnt++;
        }
        
        if(cnt > n/2) return el;
        return -1;
        
    }
};