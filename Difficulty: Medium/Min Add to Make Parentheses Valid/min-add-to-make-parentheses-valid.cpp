class Solution {
  public:
    int minParentheses(string& s) {
       int n = s.size();
       
       int need = 0;
       int open_p = 0;
       for(int i = 0; i < n; i++){
           if(s[i] == '(') open_p++;
           else{
               if(open_p > 0) open_p--;
               else need++;
           }
       }
        return open_p + need;
    }
};