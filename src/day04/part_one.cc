module;

#include <string>
#include <numeric>
#include <vector>

export module part_one;

export namespace part_one {
int64_t count_xmas(const std::vector<std::string>& grid) {
    const int8_t dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
    const int8_t dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

    const std::string WORD = "XMAS";
    int64_t count = 0;

    for (auto i = 0; i < grid.size(); ++i) {
        for (auto j = 0; j < grid[0].size(); ++j) {
            for (int d = 0; d < 8; ++d) {
                bool found = true;
                int64_t r = i;
                int64_t c = j;

                for (char ch : WORD) {
                    if (r < 0 || r >= grid.size() ||
                        c < 0 || c >= grid[0].size() ||
                        grid[r][c] != ch) {
                        found = false;
                        break;
                    }

                    r += dx[d];
                    c += dy[d];
                }

                if (found) {
                    ++count;
                }
            }
        }
    }
    return count;
}
}
