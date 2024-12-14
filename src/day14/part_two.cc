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

export module part_two;

export namespace part_two {

double zeroes_freq(const std::vector<uint64_t>& grid) {
    double total = static_cast<double>(grid.size());
    size_t zero_count = std::count(grid.begin(), grid.end(), 0);
    return static_cast<double>(zero_count) / total;
}

uint64_t solve(vector<input::Robot> robots, uint64_t duration, int64_t w, int64_t h) {
    vector<uint64_t> grid(w * h, 0);

    double min_entropy = std::numeric_limits<double>::max();
    uint64_t t_min = 0;

    for (int64_t t = 0; t < duration; ++t) {
        for (auto& robot : robots) {
            robot.pos.x = (((robot.pos.x + robot.velocity.x) % w) + w) % w;
            robot.pos.y = (((robot.pos.y + robot.velocity.y) % h) + h) % h;
            size_t index = static_cast<size_t>(robot.pos.y * w + robot.pos.x);
            grid[index]++;
        }

        double entropy = zeroes_freq(grid);
        if (entropy < min_entropy) {
            min_entropy = entropy;
            t_min = static_cast<uint64_t>(t + 1);
        }

        fill(grid.begin(), grid.end(), 0);
    }
    return t_min;
}
}
