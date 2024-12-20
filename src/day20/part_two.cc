module;

#include <vector>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>

import input;
import part_one;

export module part_two;

export namespace part_two {
using Position = std::pair<int, int>;
using Path = std::vector<Position>;
using Grid = std::vector<std::string>;

constexpr int SAVE_DISTANCE = 100;
constexpr int MIN_SAVINGS = 100;
constexpr int MAX_DISTANCE = 20;

int solve(const Grid& grid, const Position& start, const Position& goal) {
    Path path = part_one::bfs(grid, start, goal);
    std::map<Position, int> path_map;
    for (size_t i = 0; i < path.size(); ++i) {
        path_map[path[i]] = static_cast<int>(i);
    }

    int count = 0;

    for (size_t i = 0; i < path.size(); ++i) {
        const auto& pos = path[i];

        for (int d = 1; d <= MAX_DISTANCE; ++d) {
            for (const auto& neighbor : part_one::distance(pos, d)) {
                auto it = path_map.find(neighbor);
                if (it != path_map.end()) {
                    int savings = it->second - static_cast<int>(i) - d;
                    if (savings >= MIN_SAVINGS) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}
}
