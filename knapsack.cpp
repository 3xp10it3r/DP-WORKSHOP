/*
Problem Statement: 0/1 Knapsack Problem

You are given weights and values of N items, and a knapsack with a maximum capacity W. 
Your task is to determine the maximum value that can be obtained by putting items into the knapsack, 
ensuring that the total weight does not exceed the knapsack’s capacity.

Constraints:
1. Each item can either be included in the knapsack or excluded (0/1 property).
2. You cannot break an item — you either take it or leave it.

Input:
- N: Number of items (integer)
- W: Maximum capacity of the knapsack (integer)
- weights[]: Array of item weights (size N)
- values[]: Array of item values (size N)

Output:
- The maximum value achievable without exceeding the weight capacity.

Example:
Input:
N = 4, W = 8
weights[] = {2, 3, 4, 5}
values[] = {3, 4, 5, 6}

Output:
9

Explanation:
Items with weights 3 and 5 give the maximum value (4 + 6 = 9) without exceeding the weight limit.

*/



#include<bits/stdc++.h>

using namespace std;

int dp[21][110];

int rec(int level, int weight_taken, int w, vector<int>& weights, vector<int>& values, int n) {
    if(level == n) {
        return 0;
    }

    if(dp[level][weight_taken] != -1)
        return dp[level][weight_taken];

    int ans = rec(level + 1, weight_taken, w, weights, values, n);

    if(weight_taken + weights[level] <= w) {
       ans = max(ans, values[level] + rec(level+1, weight_taken + weights[level], w, weights, values, n));
    }
    
    return dp[level][weight_taken] = ans;
}

int main() {
    int t, n, w;
    cin >> t;

    while(t--) {
        cin >> n >> w;
        
        vector<int> weights(n), values(n);
        
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            cin >> weights[i] >> values[i];
        }

        cout << rec(0, 0, w, weights, values, n) << endl;
    }

    return 0;
}
