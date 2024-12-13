module;

#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <cstdint>
#include <tuple>
#include <iostream>
#include <cmath>
#include <numeric>

import input;

export module part_one;

export namespace part_one {

uint64_t calculate_cost(const std::vector<uint64_t>& machine) {
    const int64_t ax = static_cast<int64_t>(machine[0]);
    const int64_t ay = static_cast<int64_t>(machine[1]);
    const int64_t bx = static_cast<int64_t>(machine[2]);
    const int64_t by = static_cast<int64_t>(machine[3]);
    const int64_t cx = static_cast<int64_t>(machine[4]);
    const int64_t cy = static_cast<int64_t>(machine[5]);

    const int64_t determinant = ax * by - ay * bx;
    if (determinant == 0) return 0;

    const int64_t numerator_a = cx * by - cy * bx;
    const int64_t numerator_b = ax * cy - ay * cx;

    if (numerator_a % determinant != 0 || numerator_b % determinant != 0) return 0;

    const int64_t a = numerator_a / determinant;
    const int64_t b = numerator_b / determinant;

    if (a < 0 || b < 0) return 0;

    return static_cast<uint64_t>(a * 3 + b);
}

uint64_t solve(const std::vector<std::vector<uint64_t>>& machines, uint64_t n) {
    uint64_t sum = 0;

    for (const auto& machine : machines) {
        std::vector<uint64_t> adjusted_machine = machine;
        adjusted_machine[4] += n;
        adjusted_machine[5] += n;

        uint64_t cost = calculate_cost(adjusted_machine);
        if (cost > 0) {
            sum += cost;
        }
    }

    return sum;
}

}
