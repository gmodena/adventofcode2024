module;

#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cstdint>

import input;

using namespace std;

export module part_one;

export namespace part_one {

uint64_t count_stones(const std::vector<int64_t>& values, int64_t iterations) {
    std::unordered_map<uint64_t, uint64_t> freq;

    for (int value : values) {
        freq[value]++;
    }

    for (int64_t _ = 0; _ < iterations; ++_) {
        std::unordered_map<uint64_t, uint64_t> next_freq;

        for (const auto& [value, count] : freq) {
            if (value == 0) {
                next_freq[1] += count;
            } else {
                uint64_t high, low;
                uint64_t num_digits = static_cast<uint64_t>(std::log10(value)) + 1;

                if (num_digits % 2 == 0) {
                    uint64_t divisor = static_cast<uint64_t>(std::pow(10, num_digits / 2));
                    high = value / divisor;
                    low = value % divisor;
                    next_freq[high] += count;
                    next_freq[low] += count;
                } else {
                    next_freq[value * 2024] += count;
                }
            }
        }

        freq = std::move(next_freq);
    }

    uint64_t total_count = 0;
    for (const auto& [_, count] : freq) {
        total_count += count;
    }

    return total_count;
}

std::uint64_t solve(const std::vector<int64_t>& values, int iterations) {
    return count_stones(values, iterations);    
}
}