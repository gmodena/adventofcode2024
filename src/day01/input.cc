module;

#include <ranges>
#include <vector>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <cstdint>

export module input;

namespace {
const std::string_view day01 = R"(3   4
4   3
2   5
1   3
3   9
3   3)";
}

export namespace input {
std::pair<std::vector<int64_t>, std::vector<int64_t>> parsed() {
    std::vector<int64_t> left_list, right_list;
    std::istringstream iss((std::string(day01)));
    
    int64_t left, right;
    while (iss >> left >> right) {
        left_list.push_back(left);
        right_list.push_back(right);
    }
    return std::make_pair(left_list, right_list);
}  
}