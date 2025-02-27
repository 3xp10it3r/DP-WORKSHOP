// Link : https://maang.in/problems/Bricks-Colouring-181?resourceUrl=cs70-cp476-pl3255-rs181&returnUrl=%5B%22%2Fcourses%2FDP-Workshop-Vivek-Gupta-Youtube-70%3Ftab%3Dchapters%22%5D

// Description
// You are given N bricks in a line and M different coloured buckets of paint. You have to find the number of ways you can colour the brick wall such that there are exactly K positions out of the N bricks such that it has a different colour from the brick wall on its immediate left. (except the first brick, since there is no left brick). Print it modulo 10^9+7.

// Input Format
// The first line of the input contains one integer T - the number of test cases. Then T test cases follow.


// The first and only line of each test case contains three space-separated integers N, M, K.

// Output Format
// For each test case, print the number of ways you can colour the brick wall satisfying the given condition % 10^9+7.

// Constraints
// 1≤ T ≤ 100

// 1≤ N, M ≤ 2000

// 0≤ K ≤ N-1

// It is guaranteed that the sum of N*K over all test cases does not exceed 4*108.

// Sample Input 1
// 3
// 3 2 2
// 2 2 1
// 3 5 0
// Sample Output 1
// 2
// 2
// 5
// Note
// For the first test case, the following are the 2 different arrangements possible:



// [1, 2, 1]

// [2, 1, 2]


// For the second test case, the following are the 2 different arrangements possible:



// [1, 2]

// [2, 1]


#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[2010][2010];

int rec(int level, int mColors, int breakpoints, int n) {
    // if (breakpoints < 0) 
    //     return 0;

    if(level == n)
        if(breakpoints == 0) 
            return 1;
        else return 0;

    if(dp[level][breakpoints] != -1)
        return dp[level][breakpoints];
    
    int ans = rec(level + 1, mColors, breakpoints, n) % MOD; // if we color it with same as prev color then 1 way.
    
    ans += (1LL * (mColors - 1) * (rec(level + 1, mColors, breakpoints - 1, n) % MOD)) % MOD; // if we don't color as last color then we can color it in m - 1 ways.
    ans %= MOD;

    return dp[level][breakpoints] = ans;
}

int main() {
    int t, n, m, k;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> m >> k;
        cout << (1LL * m * rec(1, m, k, n)) % MOD << endl; // multiplied with m because for 1st bricks there's m ways to color it.
    }

    return 0;
}
