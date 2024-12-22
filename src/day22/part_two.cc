module;

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
#include <limits>
#include <cstdint>


import part_one;

export module part_two;

using namespace std;

export namespace part_two {

std::map<std::array<uint64_t, 4>, uint64_t> sell_sequences(uint32_t initial_secret, int iterations) {
    uint32_t secret = initial_secret;
    std::vector<uint64_t> prices;

    prices.push_back(secret % 10);
    for (uint64_t i = 0; i < iterations; ++i) {
        secret = part_one::next_secret(secret);
        prices.push_back(secret % 10);
    }

    std::map<std::array<uint64_t, 4>, uint64_t> sequences;
    for (size_t i = 0; i < prices.size() - 4; ++i) {
        std::array<uint64_t, 4> sequence = {
            prices[i + 1] - prices[i],
            prices[i + 2] - prices[i + 1],
            prices[i + 3] - prices[i + 2],
            prices[i + 4] - prices[i + 3]
        };

        if (sequences.find(sequence) == sequences.end()) {
            sequences[sequence] = prices[i + 4];
        }
    }

    return sequences;
}

uint64_t solve(std::vector<uint32_t> initial_secrets) {
    const int iterations = 2000;

    std::map<std::array<uint64_t, 4>, uint64_t> cache;

    for (uint32_t initial_secret : initial_secrets) {
        auto sequences = sell_sequences(initial_secret, iterations);
        for (const auto& [sequence, price] : sequences) {
            cache[sequence] += price;
        }
    }

    uint64_t sum = 0;
    for (const auto& [sequence, price] : cache) {
        sum = std::max(sum, price);
    }

    return sum;
}
}
