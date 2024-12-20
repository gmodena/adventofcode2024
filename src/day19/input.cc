module;

#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <cstdint>
#include <tuple>
#include <iostream>

export module input;

export namespace input {
std::string day19_small = R"(r, wr, b, g, bwu, rb, gb, br

brwrr
bggr
gbbr
rrbgbr
ubwu
bwurrg
brgr
bbrgwb)";

std::string day19 = R"()";

std::tuple<std::vector<std::string>, std::vector<std::string>> parsed(const std::string& in) {
    std::vector<std::string> patterns, towels;
    std::stringstream ss(in);
    std::string line;
    
    if (std::getline(ss, line)) {
        std::stringstream pattern_ss(line);
        std::string pattern;
        while (std::getline(pattern_ss, pattern, ',')) {
            size_t start = pattern.find_first_not_of(' ');
            patterns.push_back(start == std::string::npos ? "" : pattern.substr(start));
        }
    }
    
    std::getline(ss, line);
    while (std::getline(ss, line)) {
        towels.push_back(line);
    }
    
    return {patterns, towels};
}

}
