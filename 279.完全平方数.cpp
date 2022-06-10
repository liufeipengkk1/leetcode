/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 1;
        }

        vector<int> dp(n + 1, 0);

        // a number can be represent i = j^2 + (i - j^2)
        // so the optimal substructure is f(i) = 1 + min(f(i - j^2))
        // bound: f(0) = 0 (used to ensure  min(i - j^2) is zero).
        // and i >= j^2, so j >= 1
        for (int i = 1; i <= n; i++) {
            int t = INT_MAX;
            for (int j = 1; j <= sqrt(i); j++) {// j start from 1
                t = min(dp[i - j * j], t);
            }
            dp[i] = t + 1;
        }

        return dp[n];
    }
};
// @lc code=end

