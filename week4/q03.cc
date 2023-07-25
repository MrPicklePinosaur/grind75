class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> T(amount+1, -1);
        T[0] = 0;

        for (int i = 1; i < amount+1; ++i) {
            for (auto& coin : coins) {
                // In bounds and previous combination is possible
                if (i-coin >= 0 && T[i-coin] != -1) {
                    // special case if it's our first time setting this cell
                    if (T[i] == -1) {
                        T[i] = T[i-coin]+1;
                    } else {
                        T[i] = min(T[i-coin]+1, T[i]);
                    }
                }
            }
        }
        return T[amount];
    }
};
