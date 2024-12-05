module;

#include <string>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <cstdint>

export module part_one;

export namespace part_one {

int64_t is_valid(const std::map<std::int64_t, std::set<std::int64_t>>& rules, const std::vector<int64_t>& order) {
    std::map<int, int> positions;
    for (size_t i = 0; i < order.size(); ++i) {
        positions[order[i]] = i;
    }

    for (const auto& [before, after_set] : rules) {
        if (positions.count(before)) {
            int before_pos = positions[before];
            for (int after : after_set) {
                if (positions.count(after)) {
                    int after_pos = positions[after];
                    if (before_pos >= after_pos) {
                        return false;
                    }
                }
            }
        }
     }
     return true;
}

int64_t count_mid(const std::map<std::int64_t, std::set<std::int64_t>>& rules, const std::vector<std::vector<int64_t>>& orders) {
    int64_t sum = 0;

    for (auto order: orders) {
        if (is_valid(rules, order))
            sum += order[order.size() / 2];
    }
    return sum;
}
}
