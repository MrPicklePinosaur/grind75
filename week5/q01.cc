
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l < r) {
            int m = l + floor((r-l)/2);

            if (nums.at(m) == target) {
                return m;
            }

            // two cases, check if we are in left or right subarrays
            if (nums.at(l) <= nums.at(m)) {
                if (target < nums.at(l) || nums.at(m) < target) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            } else {
                if (target < nums.at(m) || nums.at(r) < target) {
                    r = m-1;
                } else {
                    l = m+1;
                }

            }
        }

        return nums.at(l) == target ? l : -1;
    }
};
