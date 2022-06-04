/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int Fn_2 = 0;
        int Fn_1 = 1;
        int Fn = Fn_1 + Fn_2;
        for (int i = 3; i <= n; i++) {
            Fn_2 = Fn_1;
            Fn_1 = Fn;
            Fn = Fn_1 + Fn_2;
        }
        return Fn;
    }
};
// @lc code=end

