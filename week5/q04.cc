
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort input by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;
        vector<int> cur = intervals.at(0);

        for (auto i = 1; i < intervals.size(); ++i) {

            auto interval = intervals.at(i);

            // check if we should merge the intervals 
            if (interval[0] <= cur[1]) {
                cur = { min(cur[0], interval[0]), max(cur[1], interval[1]) };
            } else {
                output.push_back(cur);
                cur = interval;
            }
        }
        output.push_back(cur);

        return output;
    }
};
