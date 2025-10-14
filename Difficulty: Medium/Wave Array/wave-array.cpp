class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = 0;
        while(i < n-1){
            if(arr[i] < arr[i+1]){
                swap(arr[i],arr[i+1]);
                i += 2;
            }
            else if(arr[i] < arr[i-1]){
                swap(arr[i],arr[i-1]);
                i += 2;
            }
            else i+=2;
        }
    }
};