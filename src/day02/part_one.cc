module;

#include <vector>
#include <algorithm>
#include <cstdint>
#include <ranges>

export module part_one;

export namespace part_one {

constexpr int64_t MAX_DIFF = 3;
constexpr int64_t MIN_DIFF = 1;
constexpr bool DECREASING = false;
constexpr bool INCREASING = true;

bool is_ordered(const std::vector<int64_t>& level, bool increasing) {
    return std::all_of(level.begin() + 1, level.end(), [&](const int64_t& cur) {
        const auto prev = &cur - 1;
        return increasing ? 
               (cur > *prev && cur - *prev <= MAX_DIFF) : 
               (cur < *prev && *prev - cur <= MAX_DIFF);
    });
}

int64_t is_safe(const std::vector<std::vector<int64_t>>& levels) {
    return std::ranges::count_if(levels, [](const std::vector<int64_t>& level) {
        return is_ordered(level, INCREASING) || is_ordered(level, DECREASING);
    });
}
}
