module;

#include <string>
#include <regex>
#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>
export module part_two;

export namespace part_two {
int64_t repair_memory(std::string &memory) {
    const std::regex mul_pattern(R"(mul\((\d+)\s*,\s*(\d+)\))");
    const std::regex instruction_pattern(R"(mul\((\d+)\s*,\s*(\d+)\)|do\(\)|don't\(\))");

    bool enabled = true;
    int64_t sum = 0;
    
    std::sregex_iterator it(memory.begin(), memory.end(), instruction_pattern);
    std::sregex_iterator end;

    while (it != end) {
        std::string match = (*it).str();
        if (match == "do()") {
            enabled = true;
        } else if (match == "don't()" ) {
            enabled = false;
        } else if (enabled) {
            std::smatch mul_match;
            if (std::regex_search(match, mul_match, mul_pattern)) {
                sum += std::stoi(mul_match[1]) * std::stoi(mul_match[2]);
            }
        }
         ++it;
    }
    return sum;
}
}
