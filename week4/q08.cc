class Solution {
public:

    void discoverFresh(vector<vector<int>>& grid, set<pair<int, int>>& almost_rotten, pair<int, int> cell) {
        auto HEIGHT = grid.size();
        auto WIDTH = grid.at(0).size();

        const vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dir_x, dir_y] : dirs) {
            auto next_x = cell.first + dir_x;
            auto next_y = cell.second + dir_y;

            if (0 <= next_x && next_x < WIDTH && 0 <= next_y && next_y < HEIGHT && grid.at(next_y).at(next_x) == 1) {
                almost_rotten.insert({next_x, next_y});
                // cout << "discovered " << next_x << "," << next_y << "\n";
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // find longest path from a fresh orange to a rotten orange

        auto HEIGHT = grid.size();
        auto WIDTH = grid.at(0).size();

        int fresh_count = 0;

        // list of oranges to be rotted in the next cycle
        deque<pair<int, int>> q;

        for (auto j = 0; j < HEIGHT; ++j) {
            for (auto i = 0; i < WIDTH; ++i) {

                if (grid.at(j).at(i) == 2) {

                    // discover all fresh oranges around the rotten orange
                    discoverFresh(grid, almost_rotten, { i ,j});

                }

            }
        }


        return -1;
    }
};

// second solution
class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        
        const vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        auto HEIGHT = grid.size();
        auto WIDTH = grid.at(0).size();

        // list of oranges to be rotted in the next cycle
        deque<pair<int, int>> q;

        int fresh_count = 0;

        for (auto j = 0; j < HEIGHT; ++j) {
            for (auto i = 0; i < WIDTH; ++i) {
                if (grid.at(j).at(i) == 1) ++fresh_count;
                if (grid.at(j).at(i) == 2)  q.push_back({i,j});
            }
        }

        // run multisource bfs
        int time = 0;
        while (q.size() > 0 && fresh_count > 0) {

            int size = q.size();
            for (auto i = 0; i < size; ++i) { 
                auto [cur_x, cur_y] = q.front();
                q.pop_front();
    
                // look for next oranges
                for (auto [dir_x, dir_y] : dirs) {
                    auto next_x = cur_x + dir_x;
                    auto next_y = cur_y + dir_y;
    
                    if (0 <= next_x && next_x < WIDTH && 0 <= next_y && next_y < HEIGHT && grid.at(next_y).at(next_x) == 1) {
                        q.push_back({next_x, next_y});
                        --fresh_count;
                        grid[next_y][next_x] = 2;
                    }
                }
            }
            ++time;

        }

        return fresh_count > 0 ? -1 : time;
    }
};
