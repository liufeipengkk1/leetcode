/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
//这个题其实可以看出是个背包问题，但我已经忘了
/*
1. 和为奇数不可能
2.  寻找一个组合，和为T = total / 2,
    对于长度len,判断f(len)是否满足, 只需要判断f(len - 1)是否满足，
    如果满足返回true，如果不满足，那么需要判断f(len - 1)是否为(T - N(len))
    推断出: 可以用动态规划来解，因为已经出现子问题.
    可以看出: 对于前i个数，假设我们知道所有f(1..i)的情况，那么f(i + 1)也能推断出来,
    原因如下: 
        假设f[i][j]表示前i个数，能凑出j来,那么f[i+1][j]也能成立
        如果f[i][j]表示前i个数不能凑出j来，那么如果f[i][j-a]成立(a为i+1的值),自然也成立
        关键子问题: f[i][j]，前i个数，所有可能凑出来的结果。 j属于[0, T]

        关键点: 对于每一个i，都要求所有的j的可能性
        转移方程： f[i][j] = true, 如果 f[i-1][j] == true
            or    f[i][j] = f[i-1][j - nums[i]]
            总结起来: f[i][j] = f[i-1][j] | f[i-1][j - nums[i]]
        
        遍历方向: 正向遍历即可
        边界(卡了一会,其实体积为0就是边界): j = 0，所有f[i][0]都满足, 
*/    
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
       
        int target = 0;
        for (int i = 0; i < len; i++) {
            target += nums[i];
        }

        if ((target % 2) != 0) {
            return false;
        }

        target = target / 2;

        vector<vector<bool>> dp;
        dp.resize(len, vector(target + 1, false));
        for (int i = 0; i < len; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 1; j <= target; j++) {
                if (j - nums[i] < 0) { //不存在这个数
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j - nums[i]];
                }
            }
        }

        return dp[len - 1][target];
    }
    
};
// @lc code=end
