// Link https://maang.in/problems/Subset-Sum-Queries-760?resourceUrl=cs70-cp476-pl3255-rs760&returnUrl=%5B%22%2Fcourses%2FDP-Workshop-Vivek-Gupta-Youtube-70%3Ftab%3Dchapters%22%5D

// Given an array of size N, and Q queries, for each query, you need to get the indices of the elements of the array whose subset-sum is equal to the queried sum i, if possible 1, else return -1.

// Complete the Function subset_queries( vector &arr, vector &queries ) that takes vector a and queries vector as input.

// Input Format
// The first line of input contains two integers - 
// N,Q where 
// N is the size of the array and 
// Q is a number of queries.
// The second line of input contains 
// N space-separated integers, which are array elements.
// The third line of input contains 
// Q space-separated integers, which are queries.

// Output Format
// Return a vector < vector < int > > having 
// 0-based indices of the elements of the array whose subset-sum is equal to the queried sum 
// sum i
// ​for each ith query, if possible, else return vector { −1 }.
// If the returned vector < vector < int > > from the function subset_queries( vector &arr, vector &queries ) is valid, then the program prints 1. Otherwise, prints -1.

// N <= 100
// Q <= 10^5
// arr[i] <= 10^5
// sum i <= 10^5

#include <bits/stdc++.h>
using namespace std;


#define ll int64_t

int dp[105][100010];

int rec(int level, int sum_left, vector<int>& arr, int n) {
    if(sum_left < 0) 
        return 0;
    
    if(level == n) {
        if(sum_left == 0)
            return 1;
        else 
            return 0;
    }

    if(dp[level][sum_left] != -1) 
        return dp[level][sum_left];

    int ans = rec(level + 1, sum_left, arr, n) || rec(level + 1, sum_left - arr[level], arr, n);

    return dp[level][sum_left] = ans;
}

void printSet(int level, int sum_left, vector<int>& arr, int n, vector<int>& cur) {
    if(level == n) {
        return;
    }

    if(rec(level + 1, sum_left, arr, n)) {
        printSet(level + 1, sum_left, arr, n, cur);
    } else if(rec(level + 1, sum_left - arr[level], arr, n)){
        cur.push_back(level);
        printSet(level + 1, sum_left - arr[level], arr, n, cur);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    int n = arr.size();
    vector<vector<int>> ans;
    memset(dp, -1, sizeof(dp));

    for(auto sum_left : queries) {
        vector<int> cur;
        if(rec(0, sum_left, arr, n)) {
            printSet(0, sum_left, arr, n, cur);
            ans.push_back(cur);
        } else {
            ans.push_back({-1});
        }
    }

    return ans;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
