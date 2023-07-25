class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // technically can scan for one zero case and two or more zero case

        // approach: multiply prefix products and suffix products
        vector<int> ans(nums.size(), 1);
        int prod = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] *= prod;
            prod *= nums[i];
        }

        prod = nums[nums.size()-1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            ans[i] *= prod;
            prod *= nums[i];
        }

        /*
        for (int i = 0; i < nums.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        */
        return ans;
    }
};
