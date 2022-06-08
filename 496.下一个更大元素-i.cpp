/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    /*进阶:
     时间复杂度为(nums1.length + nums2.length)
     使用hashMap + 单调栈，查找的时间复杂度为1
     */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> hashMap;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while (!st.empty() && num >= st.top()) {
                st.pop();
            }
            hashMap[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }

        vector<int> ret(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            ret[i] = hashMap[nums1[i]];
        }

        return ret;
    }
};
// @lc code=end

