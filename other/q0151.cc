
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;

        ss >> token;
        string ans = token;
        while (ss >> token) ans = token + " " + ans;

        return ans;
    }
};
