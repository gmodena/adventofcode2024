module;

#include <vector>
#include <cstdint>

export module part_two;

export namespace part_two {

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

bool is_safe_with_removal(std::vector<int64_t> level) {
    if (is_increasing(level) || is_decreasing(level)) {
        return true;
    }

    for (size_t i = 0; i < level.size(); ++i) {
        std::vector<int64_t> modified_level = level;
        modified_level.erase(modified_level.begin() + i);

        if (is_increasing(modified_level) || is_decreasing(modified_level)) {
            return true;
        }
    }

    return false;
}

int64_t is_safe(std::vector<std::vector<int64_t>> levels) {
    int64_t num_safe = 0;
    
    for (auto &level : levels) {
        if (is_safe_with_removal(level)) {
            num_safe += 1;
        }
    }
    return num_safe;
}

}
