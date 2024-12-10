module;

#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

export module part_two;

export namespace part_two {
const vector<pair<int64_t, int64_t>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int64_t dfs(const vector<vector<int64_t>>& grid, int64_t row, int64_t col) {
    int64_t rows = grid.size();
    int64_t cols = grid[0].size();

    if (grid[row][col] == 9) {
        return 1;
    }

    int64_t count = 0;

    for (const auto& [dr, dc] : directions) {
        int64_t next_row = row + dr;
        int64_t next_col = col + dc;

        if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols &&
            grid[next_row][next_col] == grid[row][col] + 1) {
            count += dfs(grid, next_row, next_col);
        }
    }

    return count;
}

int64_t solve(vector<vector<int64_t>> grid) {
    int64_t rating = 0;

    for (int64_t i = 0; i < grid.size(); ++i) {
        for (int64_t j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 0) {
                rating += dfs(grid, i, j);
            }
        }
    }
    return rating;
}
}
