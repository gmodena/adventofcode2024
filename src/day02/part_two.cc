module;

#include <vector>
#include <algorithm>
#include <cstdint>
#include <ranges>

import part_one;
using namespace part_one;

export module part_two;

export namespace part_two {

bool is_safe_with_removal(std::vector<int64_t> level) {
    if (is_ordered(level, INCREASING) || is_ordered(level, DECREASING)) {
        return true;
    }

    for (size_t i = 0; i < level.size(); ++i) {
        std::vector<int64_t> modified_level = level;
        // FIXME: avoid creating and resizing a new array at each iteration.
        modified_level.erase(modified_level.begin() + i);

        if (part_one::is_ordered(modified_level, INCREASING) || part_one::is_ordered(modified_level, DECREASING)) {
            return true;
        }
    }

    return false;
}

int64_t is_safe(const std::vector<std::vector<int64_t>>& levels) {
    return std::ranges::count_if(levels, [](const std::vector<int64_t>& level) {
        return is_safe_with_removal(level);
    });
}

}
