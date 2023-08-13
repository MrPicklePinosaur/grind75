class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int H = matrix.size(), W = matrix[0].size();

        int l = 0, r = W, t = 0, b = H;

        vector<int> out;

        while (true) {
            for (int i = l; i < r; ++i) out.push_back(matrix.at(t).at(i));
            ++t;
            if (!(l < r && t < b)) break;
            for (int j = t; j < b; ++j) out.push_back(matrix.at(j).at(r-1));
            --r;
            if (!(l < r && t < b)) break;
    
            for (int i = r-1; i >= l; --i) out.push_back(matrix.at(b-1).at(i));
            --b;
            if (!(l < r && t < b)) break;
            for (int j = b-1; j >= t; --j) out.push_back(matrix.at(j).at(l));
            ++l;
            if (!(l < r && t < b)) break;
        }

        // go one level deeper
        //++l;
        //--r;
        //++t;
        //--b;

        //cout << l << " " << r << " " << t << " " << b << "\n"; 


        return out;
    }
};
