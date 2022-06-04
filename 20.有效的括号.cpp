/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.length() < 1) {
            return false;
        }

        stack<char> parentheses;
        map<char, char> pMap = {
            {'(',')'},
            {'[',']'},
            {'{','}'},
        };
        for (int i = 0; i < s.length(); i++) {
            char cur = s[i];
            if (parentheses.empty()) {
                if (cur == '(' || cur == '[' || cur == '{') {
                    parentheses.push(s[i]);
                    continue;
                } else {
                    return false;
                }
            }

            char ch = parentheses.top();
            if (pMap[ch] == s[i]) {
                parentheses.pop();
            } else {
                parentheses.push(s[i]);
            }
        }

        return parentheses.empty();
    }
};
// @lc code=end

