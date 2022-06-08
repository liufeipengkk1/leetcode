/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    //132patther,即中间的值为最大值 i,j,k, jk弄成一个单调栈，并且记录j..k的最小值
    
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return false;
        }
        
        int left_min = nums[0];
        multiset<int> right_all;
        for (int k = 2; k < len; k++) {
            right_all.insert(nums[k]);
        }

        for (int j = 1; j < len - 1; j++) {
            if (left_min < nums[j]) {
                auto it = right_all.upper_bound(left_min);
                if (it != right_all.end() && *it < nums[j]) {
                    return true;
                }
            }
            left_min = min(left_min, nums[j]);
            right_all.erase(right_all.find(nums[j+1]));
        }
        return false;
    }
};
// @lc code=end

