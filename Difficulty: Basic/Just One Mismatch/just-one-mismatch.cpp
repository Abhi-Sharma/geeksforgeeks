class Solution {
    bool check(string arr, string S, int N){
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != S[i]) cnt++;
        }
        if(cnt == 1) return true;
        return false;
    }
  public:
    string isStringExist(vector<string> arr, int N, string S) {
        for(int i = 0; i < N; i++){
            if(arr[i].size() == S.size()){
                if(check(arr[i],S,N) == true) return "True";
            }
        }
        return "False";
    }
};