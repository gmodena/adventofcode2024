module;

#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <cstdint>
#include <iostream>

export module input;

export namespace input {
std::string day07_small = R"(190: 10 19
3267: 81 40 27
83: 17 5
156: 15 6
7290: 6 8 6 15
161011: 16 10 13
192: 17 8 14
21037: 9 7 18 13
292: 11 6 16 20)";

std::string day07 = R"()";

std::map<std::int64_t, std::vector<std::int64_t>> parsed(std::string in) {
    std::istringstream iss((in));
    std::string line;
    std::map<std::int64_t, std::vector<std::int64_t>> result;

    std::int64_t y = 0;

    while (std::getline(iss, line)) {
        size_t colon_pos = line.find(':');
        
        std::int64_t key = std::stoll(line.substr(0, colon_pos));
        std::vector<std::int64_t> values;

        std::istringstream value_stream(line.substr(colon_pos + 1));
        std::int64_t val;
        while (value_stream >> val) {
            values.push_back(val);
        }
        result[key] = values;

    }

    return result;
}

}
