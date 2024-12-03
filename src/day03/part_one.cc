module;

#include <string>
#include <regex>
#include <numeric>
#include <vector>
#include <ranges>

export module part_one;

export namespace part_one {
int64_t repair_memory(std::string memory) {
    const std::regex mul_pattern(R"(mul\((\d+)\s*,\s*(\d+)\))");

    int64_t sum = 0;
    for (auto it = std::sregex_iterator(memory.begin(), memory.end(), mul_pattern); it != std::sregex_iterator(); ++it) {
        int x = std::stoi((*it)[1]);
        int y = std::stoi((*it)[2]);
        sum += x*y;
    }


    return sum;
}

}
