module;

#include <ranges>
#include <vector>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <map>
#include <numeric>

export module part_two;

export namespace part_two {
int64_t similarity_score(std::vector<int64_t> left_list, std::vector<int64_t> right_list) {
    std::map<int64_t, int64_t> freq;
    std::ranges::for_each(right_list, [&freq](int64_t n) { freq[n]++; });

    return std::accumulate(
        left_list.begin(), left_list.end(), int64_t{0}, 
        [&freq](int64_t score, int64_t n) { return score + n * freq[n]; }
    );
}
}