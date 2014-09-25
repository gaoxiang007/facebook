// https://oj.leetcode.com/problems/sort-colors/


// Version 0 - counting sort
// time - O(n)   space - O(1)
class Solution {
public:
    // counting sort implementation
    void sortColors(int A[], int n) {
        int counter[3] = {0};
        for(int i = 0; i < n; ++i) {
            counter[A[i]]++;
        }
        
        for(int i = 0, index = 0; i < 3; ++i) { // NOT  i < n
            for(int j = 0; j < counter[i]; ++j) {
                A[index++] = i;
            }
        }
    }
};


// Version 1 - partition

class Solution {
public:
    
    void sortColors(int A[], int n) {
        int redStart = 0, blueStart = n - 1;
        int i = 0;
        while(i <= blueStart) {
            if(A[i] == 0) {
                swap(A[i], A[redStart]);
                i++;
                redStart++;
            } else if(A[i] == 2) {
                swap(A[i], A[blueStart]);
                blueStart--;
            } else if(A[i] == 1) {
                i++;
            }
        }// while
        
    }
};
