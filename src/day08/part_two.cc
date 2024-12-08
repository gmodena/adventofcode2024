module;

#include <unordered_map>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdint>

import input;

export module part_two;

export namespace part_two {

bool is_within_bounds(std::int64_t h, std::int64_t w, std::int64_t x, std::int64_t y) {
    return x >= 0 && x < w && y >= 0 && y < h;
}

int64_t solve(const input::Grid& grid, std::int64_t w, std::int64_t h) {
    int64_t result = 0;
    std::set<std::pair<std::int64_t, std::int64_t>> unique_points;

    auto trace_points = [&](int64_t x, int64_t y, int64_t dx, int64_t dy) {
        while (is_within_bounds(w, h, x, y)) {
            if (unique_points.insert({x, y}).second)
                ++result;
            x += dx;
            y += dy;
        }
    };

    for (const auto& [key, coords] : grid) {
        for (size_t i = 0; i < coords.size(); ++i) {
            for (size_t j = i + 1; j < coords.size(); ++j) {
                const auto& coord1 = coords[i];
                const auto& coord2 = coords[j];

                int64_t dx1 = coord1.first - coord2.first;
                int64_t dy1 = coord1.second - coord2.second;
                int64_t dx2 = coord2.first - coord1.first;
                int64_t dy2 = coord2.second - coord1.second;

                trace_points(coord1.first, coord1.second, dx1, dy1);
                trace_points(coord2.first, coord2.second, dx2, dy2);
            }
        }
    }

    return result;
}

}
