class Solution {
  public:
    /*Function to count even and odd elements in the array
     * arr : Array with its elements
     */
    pair<int, int> countOddEven(vector<int> &arr) {
       int even_cnt = 0;
       int odd_cnt = 0;
       
       for(int i = 0; i < arr.size(); i++){
           if(arr[i] % 2 == 0) even_cnt++;
           else odd_cnt++;
       }
        return {odd_cnt, even_cnt};       
    }
};