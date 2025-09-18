class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size() + 1;
        long long s1 = (n * (n + 1))/2;
        long long s2 = 0;
        for(int i = 0 ; i < arr.size(); i++){
            s2 += arr[i];
        }
        return s1-s2;
    }
};