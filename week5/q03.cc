class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        _permute(ans, nums, 0);
        return ans;
    }
    void _permute(vector<vector<int>> &ans, vector<int> &nums, int fixed) {

        if (fixed >= nums.size()) ans.push_back(nums);

        for (auto i = fixed; i < nums.size(); ++i) {
            vector<int> new_nums = vector(nums);
            auto temp = new_nums[fixed];
            new_nums[fixed] = new_nums[i];
            new_nums[i] = temp;

            _permute(ans, new_nums, fixed+1);
        }

    }
};
