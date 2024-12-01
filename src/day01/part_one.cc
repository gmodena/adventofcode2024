module;

#include <ranges>
#include <vector>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <numeric> 

export module part_one;

export namespace part_one {
int64_t pair_numbers(std::vector<int64_t> left_list, std::vector<int64_t> right_list) {
    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());
    
    return std::transform_reduce(
        left_list.begin(), left_list.end(), right_list.begin(),
        int64_t{0},
        std::plus<>(),
        [](int64_t left, int64_t right) { return std::abs(left - right); }
    );
}
}