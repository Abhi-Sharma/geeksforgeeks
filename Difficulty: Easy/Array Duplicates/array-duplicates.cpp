class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        for(int j = 1; j < arr.size(); j++){
            if(arr[j] == arr[j-1]){
                ans.push_back(arr[j]);
            }
        }
        return ans;
    }
};