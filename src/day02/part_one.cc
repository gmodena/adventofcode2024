module;

#include <vector>
#include <cstdint>

export module part_one;

export namespace part_one {

bool is_decreasing(const std::vector<int64_t> &level) {
    for (size_t i = 1; i < level.size(); ++i) {
        const auto& prev = level[i - 1];
        const auto& cur = level[i];

        if (cur >= prev || prev - cur > 3) {
            return false;
        }
    }
    return true;
}

bool is_increasing(const std::vector<int64_t> &level) {
    for (size_t i = 1; i < level.size(); ++i) {
        const auto& prev = level[i - 1];
        const auto& cur = level[i];

        if (cur <= prev || cur - prev > 3) {
            return false;
        }
    }
    return true;
}

int64_t is_safe(std::vector<std::vector<int64_t>> levels) {
    int64_t num_safe = 0;
    
    for (auto &level : levels) {
        if (is_decreasing(level) || is_increasing(level)) {
            num_safe += 1;
        }
    }
    return num_safe;
    
    }

}
