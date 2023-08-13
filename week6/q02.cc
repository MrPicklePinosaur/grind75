#define _DEBUG 0

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // subset sum with target equal to sum of array / 2
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;
        int target = floor(sum/2);

        vector<vector<bool>> T(nums.size()+1, vector(target+1, false));
        for (auto i = 0; i < nums.size()+1; ++i)  T[i][0] = true;

        // run subset sum
        for (int j = 1; j < nums.size()+1; ++j) {
            int cur_elem = nums.at(j-1);
            for (int i = 1; i < target+1; ++i) {
                int cur_target = i;

                // Don't include case
                T[j][i] = T[j][i] || T[j-1][i]; 

                // Include case
                if (i-cur_elem >= 0) T[j][i] = T[j][i] || T[j-1][i-cur_elem];
            }
        }

#if _DEBUG
        // log
        for (auto row : T) {
            for (bool cell : row) {
                if (cell) cout << "T";
                else cout << "F";
            }
            cout << "\n";
        }
#endif

        return T[nums.size()][target];
    }
};
