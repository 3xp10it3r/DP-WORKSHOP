// Link : https://leetcode.com/problems/longest-common-subsequence/description/

// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
 

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters


class Solution {
public:

    int dp[1010][1010];
    int rec(int i, int j, string& text1, string& text2, int n, int m) {
        // returns the LCS of text1[i...] & text2[j....];

        if(i >= n || j >= m) {
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        ans = max(ans, rec(i+1, j, text1, text2, n, m));
        ans = max(ans, rec(i, j+1, text1, text2, n, m));

        if(text1[i] == text2[j]) {
            ans = max(ans, 1 + rec(i+1, j+1, text1, text2, n, m));
        }
        

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, text1, text2, n, m);
    }
};


// for 3 strings

class Solution {
public:

    int dp[1010][1010][1010];
    int rec(int i, int j, int k, string& text1, string& text2, string& text3 int n, int m, int x) {
        // returns the LCS of text1[i...n-1] & text2[j....m-1] & text3[k..x-1];

        if(i >= n || j >= m || k>=x) {
            return 0;
        }

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        int ans = 0;

        ans = max(ans, rec(i+1, j, k, text1, text2, text3, n, m, x));
        ans = max(ans, rec(i, j+1, k, text1, text2, text3, n, m, x));
        ans = max(ans, rec(i, j, k+1, text1, text2, text3, n, m, x));

        if(text1[i] == text2[j] && text2[j] == text3[k]) {
            ans = max(ans, 1 + rec(i+1, j+1, k+1, text1, text2, text3, n, m, x));
        }
        

        return dp[i][j][k] = ans;
    }

    int longestCommonSubsequence(string text1, string text2, strint text3) {
        int n = text1.size(), m = text2.size(), x = text3.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, text1, text2, text3, n, m, x);
    }
};
