module;

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <tuple>
#include <array>
#include <numeric>
#include <algorithm>

import input;

using namespace std;

export module part_one;

export namespace part_one {

uint64_t solve(const vector<input::Robot>& robots, int64_t duration, int64_t w, int64_t h) {
    int64_t mid_w = w / 2;
    int64_t mid_h = h / 2;
    array<uint64_t, 4> counts = {0, 0, 0, 0};

    for (const auto& robot : robots) {
        const auto x = (((robot.pos.x + robot.velocity.x * duration) % w) + w) % w;
        const auto y = (((robot.pos.y + robot.velocity.y * duration) % h) + h) % h;

        if (x == mid_w || y == mid_h) {
            continue;
        }

        const auto quadrant = (x >= mid_w) | ((y >= mid_h) << 1);
        ++counts[quadrant];
    }

    return accumulate(counts.begin(), counts.end(), 1, multiplies<uint64_t>());
}
}
