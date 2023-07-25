class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        set<pair<int, int>> visited; // keeps track of explored island tiles
        vector<pair<int, int>> dirs { {1, 0}, { -1, 0}, {0, 1}, {0, -1}} ;
        int islands = 0;

        int HEIGHT = grid.size();
        int WIDTH = grid.at(0).size();

        for (int j  = 0; j < HEIGHT; ++j) {
            for (int i = 0; i < WIDTH; ++i) {

               //     cout << "=-=-=\n";
                if (grid.at(j).at(i) != '1'){
                    continue;
                }
                pair<int, int> pos = { i, j };
                if (visited.find(pos) != visited.end()) {
                    continue;
                }
                // BFS to explore entire island
                ++islands;

                deque<pair<int, int>> q;
                q.push_back(pos);
                visited.insert(pos);
                while (!q.empty()) {
                    auto cur = q.front();
                    // cout << cur.first << " " << cur.second << "\n";
                    q.pop_front();

                    // add next dirs
                    for (auto& [x_off, y_off] : dirs) {
                        pair<int, int> next = {cur.first+x_off, cur.second+y_off}; 
                        if (0 <= next.first && next.first < WIDTH && 0 <= next.second && next.second < HEIGHT && grid.at(next.second).at(next.first) == '1' && visited.find(next) == visited.end()) {
                            q.push_back(next);
                            visited.insert(next);
                        }
                    }
                }

            }
        }
        return islands;
    }
};
