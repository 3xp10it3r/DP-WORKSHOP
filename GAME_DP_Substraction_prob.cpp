// There are x chips, you can take y number of chips, if y = 2^m for some m belongs to [0, INF).

// First to not able to move is loser.


#include <bits/stdc++.h>
using namespace std;

int x;

int dp[100010];

int rec(int x) {
    if(x == 0) 
        return 0;
        
    if(dp[x] != -1)
        return dp[x];
        
    
    int ans = 0; 
    
    for(int m = 0; (1 << m) <= x; m++) {
        if(rec(x - (1<<m)) == 0) {
            ans = 1;
            break;
        }
    }
    
    return ans;
}


int main() {
    cin >> x;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i = 1; i < 10; i++)
    cout << rec(i) << endl;
}
