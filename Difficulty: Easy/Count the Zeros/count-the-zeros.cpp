// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            if(arr[i] == 0) cnt++;
        }
        return cnt;
    }
};