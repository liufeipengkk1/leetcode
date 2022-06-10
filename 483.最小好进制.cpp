/*
 * @lc app=leetcode.cn id=483 lang=cpp
 *
 * [483] 最小好进制
 */

// @lc code=start
class Solution {
public:
    string smallestGoodBase(string n) {
        long value = stol(n);
        int mMax = log(value)/log(2);
        
        for (int m = mMax; m > 1; m--) {
            int k = floor(pow(value, 1.0/m));
            long sum = 1, mul = 1;
            for (int i = 1; i <= m; i++) {
                mul *= k;
                sum += mul;
            }

            if (sum == value) {
                return to_string(k);
            }
        }

        // when m = 1; k = to_string(n-1)
        return to_string(value-1);        
    }
};
// @lc code=end

