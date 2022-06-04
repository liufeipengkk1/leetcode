/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        //FN = FN_1 + FN_2;
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        int FN_1 = 2;
        int FN_2 = 1;
        int FN = FN_1 + FN_2;
        for (int i = 4; i <= n; i++) {
            FN_2 = FN_1;
            FN_1 = FN;
            FN = FN_1 + FN_2;
        }

        return FN;
    }
};
// @lc code=end

