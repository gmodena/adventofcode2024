module;

#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <unordered_map>
#include <cstdint>

import input;

export module part_one;

export namespace part_one {

bool is_within_bounds(std::int64_t h, std::int64_t w, std::int64_t x, std::int64_t y) {
    return x >= 0 && x < w && y >= 0 && y < h;
}

int64_t solve(const input::Grid& grid, std::int64_t x, std::int64_t y) {
    int64_t result = 0;
    std::set<std::pair<std::int64_t, std::int64_t>> unique_points;

    for (const auto& [key, coords] : grid) {
        for (size_t i = 0; i < coords.size(); ++i) {
            for (size_t j = i + 1; j < coords.size(); ++j) {
                const auto& coord1 = coords[i];
                const auto& coord2 = coords[j];

                int x1 = 2 * coord1.first - coord2.first;
                int y1 = 2 * coord1.second- coord2.second;

                int x2 = 2 * coord2.first - coord1.first;
                int y2 = 2 * coord2.second - coord1.second;
                
                if (is_within_bounds(x, y, x1, y1))
                    unique_points.insert({x1, y1});
                    
                if (is_within_bounds(x, y, x2, y2))
                    unique_points.insert({x2, y2});
            }
        }
    }

    return unique_points.size();
}

}
