// Given a m x n grid filled with numbers, find a path from top left to bottom right, which maximizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.



#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1010][1010];

int dp[1020][1020];

int rec(int r, int c) {
    
    if(r == 0 && c == 0) {
        return arr[0][0];
    }
    
    
    if(dp[r][c] != -1) 
        return dp[r][c];
    
    int ans = -1e9;
    
    if(r!=0) {
        ans = max(ans, arr[r][c] + rec(r-1, c));
    }
    if(c!=0) {
        ans = max(ans, arr[r][c] + rec(r, c-1));
    }
    
    return dp[r][c] = ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << rec(n-1, m-1);

    return 0;
}


// If dp default value is not possible then


#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1010][1010];

int dp[1020][1020];

bool done[1020][1020]; // if dp default value is not possible then we can keep a array which will tell as if dp value is calculated or not.

int rec(int r, int c) {
    
    if(r == 0 && c == 0) {
        return arr[0][0];
    }
    
    
    if(done[r][c]) 
        return dp[r][c];
    
    int ans = -1e9;
    
    if(r!=0) {
        ans = max(ans, arr[r][c] + rec(r-1, c));
    }
    if(c!=0) {
        ans = max(ans, arr[r][c] + rec(r, c-1));
    }
    
    done[r][c] = 1;
    return dp[r][c] = ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            done[i][j] = 0; // setting as not calculated.
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << rec(n-1, m-1);

    return 0;
}
