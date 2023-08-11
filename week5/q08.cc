class Solution {
public:
    void swap(vector<int>& nums, int a, int b) {
        auto temp = nums.at(b);
        nums[b] = nums.at(a);
        nums[a] = temp;
    }

    void sortColors(vector<int>& nums) {
        int l = 0;

        // one pass to move all zeros to left size
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums.at(i)== 0) {
                swap(nums, i, l);
                ++l;
             } 
        }
        // next pass to move all ones to left size
        for (auto i = l; i < nums.size(); ++i) {
            if (nums.at(i)== 1) {
                swap(nums, i, l);
                ++l;
             } 
        }
    }

    // one pass attempt
    void _sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;

        for (auto i = 0; i < nums.size() && i <= r; ++i) {
            auto cur = nums.at(i);

            if (cur == 0) {
                swap(nums, i, l);
                ++l;
             } else if (cur == 2) {
                swap(nums, i, r);
                --r;
             } else {
                 // swap to midpoint of current pointer and the right frontier
                // swap(nums, i, floor((r-i)/2));
             }

             for (auto j = 0; j < nums.size(); ++j) {
                 cout << nums.at(j) << ",";
             }
             cout << "\n";

        }
    }
};
