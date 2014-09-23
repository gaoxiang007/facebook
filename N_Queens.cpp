

// https://oj.leetcode.com/problems/n-queens/
// http://answer.ninechapter.com/solutions/n-queens/

class Solution {
public:

    vector<string> drawChessBoard(const vector<int>& C) {
        vector<string> res;
        int N = C.size(); // square matrix
        for(int i = 0; i < N; ++i) {
            res[i] = ""; // init the ith row
            for(int j = 0; j < N; ++j) {
                if(C[i] == j) {
                    res[i].push_back('Q');
                } else {
                    res[i].push_back('.');
                }
            }
        }
        
        return res;
    }

    bool isValid(const vector<int>& C, int col) {
       int num_of_row = C.size();
       for(int i =0; i < num_of_row; ++i) {
           // check column
           if(C[i] == col) {
               return false;
           }
           
           // check diagonal
           if(i-C[i] == num_of_row - col) {
               return false;
           }
           
           // check off-diagonal
           if(i+C[i] == num_of_row + col) {
               return false;
           }
       } 
       
       return true;
       
    }

    void dfs(vector<vector<string> >& sol, int n, vector<int>& C) {
        if(C.size() == n) {
            // draw the chessboard
            sol.push_back(drawChessBoard(C));
            return;
        }
        
        for(int j = 0; j < n; ++j) {
            if(!isValid(C, j)) {
                continue;
            }
            C.push_back(j); // go to next row
            dfs(sol, n, C);
            C.pop_back();  // revoke current row
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > sol;
        if(n <= 0) {
            return sol;
        }
        vector<int> C; // c[i] = j   -> the Queen on row i is on column j
        dfs(sol, n, C);
    }
};
