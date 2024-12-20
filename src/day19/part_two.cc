module;

#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

import input;

export module part_two;

export namespace part_two {

u_int64_t solve(const std::vector<std::string>& towels, const std::vector<std::string>& patterns) {
    std::unordered_map<std::string, u_int64_t> mem;

    auto dfs = [&](const std::string& towel, const auto& dfs_ref) -> u_int64_t {
        if (towel.empty()) return 1;
        if (mem.find(towel) != mem.end()) return mem[towel];

        u_int64_t res = 0;
        for (const auto& pattern : patterns) {
            if (towel.size() >= pattern.size() && towel.substr(0, pattern.size()) == pattern) {
                res += dfs_ref(towel.substr(pattern.size()), dfs_ref);
            }
        }

        mem[towel] = res;
        return res;
    };

    u_int64_t count = 0;
    for (const auto& towel : towels) {
        count += dfs(towel, dfs);
    }

    return count;
}
}
