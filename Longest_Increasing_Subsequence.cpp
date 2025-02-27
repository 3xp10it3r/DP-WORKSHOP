// Link: https://leetcode.com/problems/longest-increasing-subsequence/description/

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 

// USING FORM ONE [SUBSETS]

class Solution {
public:
    int dp[2510][2510];

    int rec(int level, int last_taken_index, vector<int>& nums, int n) {
        if(level == n) {
            return 0;
        }

        if(dp[level][last_taken_index + 1] != -1)
            return dp[level][last_taken_index + 1];

        int ans = rec(level + 1, last_taken_index, nums, n);

        if(last_taken_index == -1 || nums[last_taken_index] < nums[level]) {
            ans = max(ans, 1 + rec(level + 1, level, nums, n));
        }
        
        // if(last_taken_index != -1)
            return dp[level][last_taken_index + 1] = ans;
        // return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        // FORM 1 se solve
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, -1, nums, n);
    }
};


// Using FORM 2 (which directly doesn't give answer so we need to look at max in dp again

class Solution {
public:
    int dp[2510];

    int rec(int level, vector<int>& nums) {
        if(level < 0) {
            return 0;
        }

        if(dp[level] != INT_MIN)
            return dp[level];

        int ans = 1; // as this element can be taken alone

        for(int prev_taken = 0; prev_taken < level; prev_taken++) {
            if(nums[prev_taken] < nums[level]) {
                ans = max(ans, 1 + rec(prev_taken, nums));
            }
        }

        return dp[level] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        // FORM 2 se solve
        int n = nums.size();
        for(int i = 0; i <= n+1; i++) {
            dp[i] = INT_MIN;
        }

        int longest = 1;

        for(int i = n-1; i >= 0; i--) {
            longest = max(longest, rec(i, nums));
        }

        return longest;
    }
};
