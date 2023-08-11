/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct Ret {
     bool p_found;
     bool q_found;
     TreeNode* ans;
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto [p_found, q_found, ans] = _lowestCommonAncestor(root, p, q);
        return ans;
    }

    Ret _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return Ret { false, false, nullptr };
        }

        bool p_found = root->val == p->val;
        bool q_found = root->val == q->val;
        TreeNode* ans = nullptr;
        if (root->left != nullptr) {
            auto [p_left, q_left, ans_left] = _lowestCommonAncestor(root->left, p, q);
            p_found = p_found || p_left;
            q_found = q_found || q_left;
            if (ans_left != nullptr) ans = ans_left;
        }
        if (root->right != nullptr) {
            auto [p_right, q_right, ans_right] = _lowestCommonAncestor(root->right, p, q);
            p_found = p_found || p_right;
            q_found = q_found || q_right;
            if (ans_right != nullptr) ans = ans_right;
        }

        if (p_found && q_found && ans == nullptr) ans = root;

        return Ret { p_found, q_found, ans};
    }

};
