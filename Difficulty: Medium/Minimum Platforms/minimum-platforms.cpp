class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
      
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int cnt = 0;
        int maxCnt = 0;
        int i = 0 , j = 0;
        while(i < arr.size()){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxCnt = max(maxCnt,cnt);
        }
        return maxCnt;
    }
};
