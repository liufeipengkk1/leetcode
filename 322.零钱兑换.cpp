/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    // 注意: coin是一种选择
    // f[j] = k, 面值为j，至少需要k枚
    // f[n] = min(f[n-coin] + 1)
    // bound: n >= 0 && n <= amount
    // f[0] = 0
    
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) {
            return -1;
        }

        vector<int> dp;
        dp.resize(amount + 1, amount + 1); 
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (const int& coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
            
        }

        if (dp[amount] == amount + 1) {
            return -1;
        }

        return dp[amount];
    }
};
// @lc code=end

