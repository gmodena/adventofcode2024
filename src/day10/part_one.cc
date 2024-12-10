module;

#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

import input;

export module part_one;

export namespace part_one {

const vector<pair<int64_t, int64_t>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

int64_t bfs(const vector<vector<int64_t>>& grid, int64_t start_row, int64_t start_col) {
    int64_t rows = grid.size();
    int64_t cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int64_t, int64_t>> q;
    
    q.push({start_row, start_col});
    visited[start_row][start_col] = true;

    int64_t reachable = 0;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (const auto& [dr, dc] : directions) {
            int64_t next_row = row + dr;
            int64_t next_col = col + dc;

            if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols &&
                !visited[next_row][next_col] &&
                grid[next_row][next_col] == grid[row][col] + 1) {

                visited[next_row][next_col] = true;
                q.push({next_row, next_col});

                if (grid[next_row][next_col] == 9) {
                    reachable++;
                }
            }
        }
    }

    return reachable;
}

int64_t solve(vector<vector<int64_t>> grid) {
    int64_t score = 0;

    for (int64_t i = 0; i < grid.size(); ++i) {
        for (int64_t j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 0) {
                score += bfs(grid, i, j);
            }
        }
    }
    return score;
}
}
