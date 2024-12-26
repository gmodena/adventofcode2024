module;

#include <ranges>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>

import input;


export module part_one;

export namespace part_one {

int solve(std::vector<std::set<std::pair<int, int>>> schematics) {
    auto is_lock = [](const auto& schematic) {
        return schematic.contains({0, 0});
    };
    
    auto partition_point = std::partition(schematics.begin(), schematics.end(), is_lock);
    
    std::span locks(schematics.begin(), partition_point);
    std::span keys(partition_point, schematics.end());

    return std::transform_reduce(
        keys.begin(), keys.end(), 0, std::plus{},
        [&](const auto& key) {
            return std::ranges::count_if(locks, 
                [&](const auto& lock) {
                    std::set<std::pair<int, int>> pairs(key.begin(), key.end());
                    auto original_size = pairs.size();
                    pairs.insert(lock.begin(), lock.end());
                    return pairs.size() == (original_size + lock.size());
                });
        });
}

}