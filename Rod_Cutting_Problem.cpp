// |------|------|---------------------------------|
// 0      2      3                                 10

// the cost of the cut =  cut made from the rod (length)

// minimize the cost.

// |------|------| |---------------------------------|   
// 0      2      3 3                                 10    => cost 10

// |------|   |-----|  and 3 to 10     cost is 3
// 0      2   2     3   


//   total cost =  10+3 = 13 

// other ways lead to more cost.



#include <bits/stdc++.h>
using namespace std;

int n;
int x[1010];

int dp[1010][1010];

int rec(int l, int r) {
    
    if(l+1 == r){
        return 0;
    }
    
    if(dp[l][r] != -1)
        return dp[l][r];
    
    int ans = 1e9;
    
    for(int p = l+1; p <= r-1; p++) {
        ans = min(ans, x[r] - x[l] + rec(l, p) + rec(p, r));
    }
    
    return dp[l][r] = ans;
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    x[0] = 0;
    
    memset(dp, -1, sizeof(dp));
    
    cout << rec(0, n) << endl;

    return 0;
}
