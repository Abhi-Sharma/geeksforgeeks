class Solution {
  public:
    string removeOuter(string& s) {
        string result = "";
        int level = 0;
        for(char ch : s){
            if(ch == '('){
                if(level > 0) result += ch;
                level++;
            }
            else if(ch == ')'){
                level--;
                if(level > 0) result += ch;
            }
        }
        return result;
        
    }
};