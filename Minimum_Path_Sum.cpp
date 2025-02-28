// Link : https://leetcode.com/problems/minimum-path-sum/description/
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200

// FORM 2 ENDING AT

class Solution {
public:

    int dp[210][210];

    int rec(int r, int c, vector<vector<int>>& grid) { // Best min sum path ending at {r, c} starting at {0,0}
        //basecase
        if(r == 0 && c == 0){
            return grid[r][c];
        }

        if(dp[r][c] != -1)
            return dp[r][c];

        int ans = INT_MAX;
        if(r!=0) {
            ans = min(ans, grid[r][c] + rec(r-1, c, grid));
        }
        if(c!=0) {
            ans = min(ans, grid[r][c] + rec(r, c-1, grid));
        }

        return dp[r][c] = ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        memset(dp, -1, sizeof(dp));
        return rec(n-1, m-1, grid);
    }
};
