class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};

        for (int num : nums) {
            vector<vector<int>> new_subsets;
            for (vector<int> subset : res) {
                subset.push_back(num);
                new_subsets.push_back(subset);
            }
            for (vector<int> new_subset : new_subsets) {
                res.push_back(new_subset);
            }
        }

        //for (auto subset : res) {
        //    for (int item : subset) cout << item << ",";
        //    cout << "\n";
        //}

        return res;
    }
};
