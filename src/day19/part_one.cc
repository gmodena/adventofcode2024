module;

#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

import input;

export module part_one;

export namespace part_one {

int solve(const std::vector<std::string>& towels, const std::vector<std::string>& patterns) {
    auto dfs = [&](const std::string& towel, const auto& dfs_ref) -> bool {
        if (towel.empty()) return true;
        for (const auto& pattern : patterns) {
            if (towel.size() >= pattern.size() && towel.substr(0, pattern.size()) == pattern) {
                if (dfs_ref(towel.substr(pattern.size()), dfs_ref)) {
                    return true;
                }
            }
        }
        return false;
    };

    int count = 0;
    for (const auto& towel : towels) {
        if (dfs(towel, dfs)) {
            ++count;
        }
    }

    return count;
}

}
