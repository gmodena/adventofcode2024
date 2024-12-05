module;

#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdint>
#include <algorithm>

import part_one;
export module part_two;

export namespace part_two {
std::vector<int64_t> reorder_update(const std::map<int64_t, std::set<int64_t>>& rules, const std::vector<int64_t>& order) {
    std::vector<int64_t> sorted_order = order;

    auto comparator = [&rules](int64_t a, int64_t b) {
        if (rules.count(a) && rules.at(a).count(b)) {
            return true;
        }
        if (rules.count(b) && rules.at(b).count(a)) {
            return false;
        }
        return a < b;
    };

    std::sort(sorted_order.begin(), sorted_order.end(), comparator);

    return sorted_order;
}

int64_t count_mid(const std::map<std::int64_t, std::set<std::int64_t>>& rules, const std::vector<std::vector<int64_t>>& orders) {
    int64_t sum = 0;

    for (auto order: orders) {
        if (!part_one::is_valid(rules, order)) {
            std::vector<std::int64_t> sorted_order = reorder_update(rules, order);
            sum += sorted_order[sorted_order.size() / 2];
        }
    }
    return sum;
}
}
