// Recursive

class Solution {
public:
    int queens[10]; // Queen[i] means on which column ith queen is placed.

    bool check(int row, int col) { // if queen can be placed at [row,col]
        for(int i = 0; i < row; i++) { // check for previous rows have any queen attacking this position
            int pRow = i;
            int pCol = queens[i];

            // abs(pCol-col) == abs(pRow - row) => checking for diagonals.

            if(pCol == col || abs(pCol-col) == abs(pRow - row)) { // anyways if cols are same then it would be a attack,
                return 0;
            }
        }

        return 1;
    }

    int rec(int level, int n) { // No of distinct ways where queen can be placed.

        //basecase 
        if(level == n) { // if we reach at nth row means we found a solution
            return 1;
        }

        //compute
        int ans = 0; 
        for(int col = 0; col < n; col++) {
            if(check(level, col)) {
                queens[level] = col;

                ans += rec(level+1, n);

                queens[level] = -1;
            }
        }

        //save and return
        return ans;
    }

    int totalNQueens(int n) {
        memset(queens, -1, sizeof(queens));
        return rec(0, n);
    }
};
