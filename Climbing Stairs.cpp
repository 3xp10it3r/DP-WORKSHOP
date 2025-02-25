// Recursive way

class Solution {
public:

    int rec(int level, int n) {
        // Basecase
        if(level == n) // if reached nth stair then 1 way add
            return 1;
        
        int ans = 0;
        // explore choices
        for(int step = 1; step <= 2; step++) {
            if(level + step <= n) { // check 
                ans += rec(level + step, n);
            }
        }

        // return 
        return ans;
    }

    int climbStairs(int n) {
        return rec(0, n);
    }
};
