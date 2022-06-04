/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 0) {
            return {};
        }

        map<int, int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto ret = result.find(target - nums[i]);
            if (ret != result.end()) {
                return {ret->second, i};
            }
            result[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

