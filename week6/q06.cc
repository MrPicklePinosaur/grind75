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
    vector<int> rightSideView(TreeNode* root) {
        auto [ret, height] = _rightSideView(root);
        return ret;
    }

    // pair of height and return value
    pair<vector<int>,int> _rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {{}, 0}; 
        }

        auto [left, left_height] = _rightSideView(root->left);
        auto [right, right_height] = _rightSideView(root->right);
        
        if (left_height > right_height) {
            auto start = left.begin() + right_height;
            auto end = left.end();
            right.insert(right.end(), start, end);
        }
        right.insert(right.begin(), root->val);
        return {right, max(left_height, right_height) + 1};
    }
};

// Better solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if (root == nullptr) return {};

        vector<int> res{};
        deque<TreeNode*> next{root};
        while (next.size() > 0) {
            res.push_back(next.back()->val);
            auto next_copy = next;
            next.clear();
            for (auto next_node : next_copy) {
                if (next_node->left != nullptr) next.push_back(next_node->left);
                if (next_node->right != nullptr) next.push_back(next_node->right);
            }
        }

        return res;
    }

};
