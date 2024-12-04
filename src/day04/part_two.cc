module;

#include <string>
#include <vector>
#include <unordered_set>

export module part_two;

export namespace part_two {
int64_t count_xmas(const std::vector<std::string>& grid) {
    const std::unordered_set<std::string> diagonals = {"MSMS", "MSSM", "SMMS", "SMSM"};
    int64_t count = 0;

    for (size_t i = 1; i < grid.size() - 1; ++i) {
        for (size_t j = 1; j < grid[i].size() - 1; ++j) {
            if (grid[i][j] == 'A') {
                std::string diagonal = {
                    grid[i + 1][j + 1],
                    grid[i - 1][j - 1],
                    grid[i + 1][j - 1],
                    grid[i - 1][j + 1]
                };

                if (diagonals.count(diagonal) > 0) {
                    ++count;
                }
            }
        }
    }

    return count;
}
}
