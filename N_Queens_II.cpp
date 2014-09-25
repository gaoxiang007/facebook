//https://oj.leetcode.com/problems/n-queens-ii/

class Solution {
public:
    
    bool isValid(const vector<int>& C, int col) {
       int num_of_row = C.size();
       for(int i =0; i < num_of_row; ++i) {
           // check column
           if(C[i] == col) {
               return false;
           }
           
           // check diagonal: if the distance between the columns equals the 
           // distance between the rows, then they're in the same diagonal
           int columnDistance = abs(C[i] - col);
           int rowDistance = num_of_row - i;
           if(columnDistance == rowDistance) {
               return false;
           }
       } 
       
       return true;
       
    }
    
    void dfs(int n, int& count, vector<int>& C) {
        if(C.size() == n) {
            count++;
            return;
        }
        
        for(int j = 0; j < n; ++j) {
            if(!isValid(C, j)) {
                continue;
            }
            
            C.push_back(j);
            dfs(n, count, C);
            C.pop_back();
        }
    }
    
    int totalNQueens(int n) {
        vector<int> C;
        int count = 0;
        dfs(n, count, C);
        return count;
    }
};
