/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    //1. 三数之和的基础上在套用循环，可以选择先排序来避免重复问题
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 4) {
            return {};
        }

        std::sort(nums.begin(), nums.end());

        int lastD = nums[len - 1] + 1;
        int lastC = nums[len - 2] + 1;
        vector<vector<int>> sumOfFour;
        for (int d = len - 1; d >= 0; d--) {
            if (lastD == nums[d]) {
                continue;
            }
            lastD = nums[d];

            for (int c = d - 1; c >= 0; c--) {
                if (lastC == nums[c]) {
                    continue;
                }    
                lastC = nums[c];

                int a = 0;
                int b = c - 1;
                if (a >= b) { //防止访问越界
                    continue;
                }
                int lastA = nums[a] - 1;
                int lastB = nums[b] + 1;
                int sumOfTwoTarget = target - nums[d] - nums[c];
                while (a < b) {
                    if (lastA == nums[a]) {
                        lastA = nums[a];
                        a++;
                        continue;
                    } else if (lastB == nums[b]) {
                        lastB = nums[b];
                        b--;
                        continue;
                    }
                    
                    int ret = nums[a] + nums[b];
                    if (ret == sumOfTwoTarget) {
                        lastA = nums[a];
                        lastB = nums[b];

                        sumOfFour.push_back({nums[a], nums[b], nums[c], nums[d]});
                        a++;
                        b--;
                    } else if (ret > sumOfTwoTarget) {
                        lastB = nums[b];
                        b--;
                    } else {
                        lastA = nums[a];
                        a++;
                    }
                }
            }
        }
        return sumOfFour;
    }
};
// @lc code=end

