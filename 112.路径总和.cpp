/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        if (isLeaf(root)) {
            return root->val == targetSum;
        }

        bool ret = hasPathSum(root->left, targetSum - root->val);
        if (!ret) {
            ret = hasPathSum(root->right, targetSum - root->val);
        }

        return ret;
    }
};
// @lc code=end

