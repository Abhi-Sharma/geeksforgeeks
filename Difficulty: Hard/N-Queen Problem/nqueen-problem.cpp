class Solution {
    void solve(int col, vector<int>& board, vector<vector<int>>& ans, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int n){

         if (col == n) {
            vector<int> temp;
            for (int i = 0; i < n; i++)
                temp.push_back(board[i] + 1);  
            ans.push_back(temp);
            return;
         }
        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
             upperDiagonal[n - 1 + col - row] == 0){
                board[col] = row;
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                solve(col + 1,board,ans,leftRow,lowerDiagonal,upperDiagonal,n);
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
  public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> board(n, 0);

        vector<int> leftRow(n,0) , lowerDiagonal(2*n-1, 0), upperDiagonal(2*n-1,0);
        solve(0,board,ans,leftRow,lowerDiagonal,upperDiagonal,n);
        return ans;
        
    }
};