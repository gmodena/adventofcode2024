module;

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <array>
#include <cstdint>


import input;

using namespace std;

export module part_one;

export namespace part_one {


struct Region {
    uint64_t area = 0;
    uint64_t perimeter = 0;
};

namespace region_utils {
    constexpr std::array<std::pair<int, int>, 4> DIRECTIONS = {{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    }};

    bool is_valid(int x, int y, uint64_t rows, uint64_t cols) {
        return x >= 0 && static_cast<uint64_t>(x) < rows && 
               y >= 0 && static_cast<uint64_t>(y) < cols;
    }

    Region bfs(const std::vector<std::string>& grid, 
               std::vector<std::vector<bool>>& visited, 
               uint64_t start_x, 
               uint64_t start_y) {
        char plant = grid[start_x][start_y];
        Region region;
        std::queue<std::pair<uint64_t, uint64_t>> q;
        
        q.emplace(start_x, start_y);
        visited[start_x][start_y] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            region.area++;

            for (const auto& [dx, dy] : DIRECTIONS) {
                int nx = static_cast<int>(x) + dx;
                int ny = static_cast<int>(y) + dy;

                if (is_valid(nx, ny, grid.size(), grid[0].size())) {
                    if (grid[nx][ny] == plant && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.emplace(nx, ny);
                    } else if (grid[nx][ny] != plant) {
                        region.perimeter++;
                    }
                } else {
                    region.perimeter++;
                }
            }
        }

        return region;
    }

    uint64_t calculate_total_cost(const std::unordered_map<char, std::vector<Region>>& region_info) {
        uint64_t total_cost = 0;
        for (const auto& [plant, regions] : region_info) {
            for (const auto& region : regions) {
                total_cost += region.area * region.perimeter;
            }
        }
        return total_cost;
    }
}

uint64_t solve(const std::vector<std::string>& grid) {
    if (grid.empty()) return 0;

    uint64_t rows = grid.size();
    uint64_t cols = grid[0].size();
    
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::unordered_map<char, std::vector<Region>> region_info;

    for (uint64_t i = 0; i < rows; ++i) {
        for (uint64_t j = 0; j < cols; ++j) {
            if (!visited[i][j]) {
                region_info[grid[i][j]].push_back(
                    region_utils::bfs(grid, visited, i, j)
                );
            }
        }
    }

    return region_utils::calculate_total_cost(region_info);
}

}
