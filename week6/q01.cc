class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> T(s.size()+1, false);
        T[s.size()] = true;

        // top down dp
        for (int i = s.size()-1; i >= 0; --i) {
            for (auto word : wordDict) {
                if (i + word.size() > s.size()) continue;

                //cout << "compare " << s.substr(i, word.size()) << " and " << word << "\n";
                if (s.substr(i, word.size()) == word)   T[i] = T[i] || T[i+word.size()];
            }
        }
       //for (bool cell : T) {
       //     if (cell) cout << "T";
       //     else cout << "F";
       // }
       // cout << "\n";

        return T[0];
    }
};
