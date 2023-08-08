class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // assuming candidates is sorted

        vector<vector<vector<int>>> T(target+1);
        T[0] = {{}};

        for (auto i = 0; i < target+1; ++i) {
            for (auto candidate : candidates) {
                if (i-candidate < 0) continue;

                // for each existing combination
                for (auto prev : T.at(i-candidate)) {
                    // ensure strictly increasing
                    if (prev.size() > 0 && candidate < prev.back()) continue;

                    auto new_list = vector(prev);
                    new_list.push_back(candidate);
                    T.at(i).push_back(new_list);

                }
            }
        }
        return T.at(target);
    }
};
