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


    for (const auto& [key, coords] : grid) {
        for (size_t i = 0; i < coords.size(); ++i) {
            for (size_t j = i + 1; j < coords.size(); ++j) {
                const auto& coord1 = coords[i];
                const auto& coord2 = coords[j];

                int64_t dx1 = coord1.first - coord2.first;
                int64_t dy1 = coord1.second - coord2.second;
                int64_t gcd1 = std::gcd(dx1, dy1);
                dx1 /= gcd1;
                dy1 /= gcd1;

                int64_t dx2 = coord2.first - coord1.first;
                int64_t dy2 = coord2.second - coord1.second;
                int64_t gcd2 = std::gcd(dx2, dy2);
                dx2 /= gcd2;
                dy2 /= gcd2;

                int64_t x1 = coord1.first;
                int64_t y1 = coord1.second;
                while (is_within_bounds(w, h, x1, y1)) {
                    unique_points.insert({x1, y1});
                    x1 += dx1;
                    y1 += dy1;
                }

                int64_t x2 = coord1.first;
                int64_t y2 = coord1.second;
                while (is_within_bounds(w, h, x2, y2)) {
                    unique_points.insert({x2, y2});
                    x2 += dx2;
                    y2 += dy2;
                }
            }
        }
    }

    return unique_points.size();
}

}
