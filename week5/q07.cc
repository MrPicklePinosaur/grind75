class UnionFind {
        vector<int> parent;
    public:

        UnionFind(int size) {
            for (int i = 0; i < size; ++i) {
                parent.push_back(i);
            }
        }

        void _union(int a, int b) {
            // TODO maybe better to choose randomly who becomes the leader
            parent[_find(a)] = _find(b);
        }

        int _find(int a) {
            if (parent.at(a) == a)  return a;
            return _find(parent.at(a));
        }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        map<string, int> emailToAccount;
        UnionFind uf(accounts.size());

        for (auto i = 0; i < accounts.size(); ++i) {
            auto account = accounts.at(i);

            for (auto it = account.begin()+1; it != account.end(); ++it) {
                string email = *it;

                auto found_email = emailToAccount.find(email) ;
                if (found_email == emailToAccount.end()) {
                    emailToAccount[email] = i;
                } else {
                    // we found email that maps to two accounts
                    uf._union(i, found_email->second);
                }
            }
        }

        map<int, vector<string>> ans;
        for (auto& [email, ind] : emailToAccount) {
            auto owner = uf._find(ind);
            if (ans.find(owner) == ans.end())  ans[owner] = {};
            ans[owner].push_back(email);
        }

        vector<vector<string>> actual_ans;
        for (auto& [id, account] : ans) {
            sort(account.begin(), account.end());
            account.insert(account.begin(), accounts[id].at(0));
            actual_ans.push_back(account);
        }

        return actual_ans;
    }
};
