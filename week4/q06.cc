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
    auto _isValidBST(TreeNode* root) {
        struct {
            int min = INT_MAX;
            int max = INT_MIN;
            bool valid = false;
            bool empty = false;
        } res;

        if (root == nullptr) {
            res.valid = true;
            res.empty = true;
            return res;
        }

        auto [lmin, lmax, lvalid, lempty] = _isValidBST(root->left);
        auto [rmin, rmax, rvalid, rempty] = _isValidBST(root->right);

        if (!lvalid || !rvalid) {
            res.valid = false;
            return res;
        }

        if (!lempty && lmax >= root->val) {
            res.valid = false;
            return res;

        }
        if (!rempty && rmin <= root->val) {
            res.valid = false;
            return res;
        }

        res.min = min(min(lmin, rmin), root->val);
        res.max = max(max(lmax, rmax), root->val);
        res.valid = true;

        return res;

        /*.
        if (root->left != nullptr && root->left->val >= root->val) {
            return false;
        }
        if (root->right != nullptr && root->right->val <= root->val) {
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
        */

    }
    bool isValidBST(TreeNode* root) {
        auto [rmin, rmax, rvalid, rempty] = _isValidBST(root);
        return rvalid;
    }
};
