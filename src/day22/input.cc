module;

#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
#include <numeric>

export module input;

export namespace input {
std::string day22_small = R"(1
10
100
2024)";

std::string day22 = R"()";

std::vector<std::uint32_t> parsed (const std::string in) {
    std::vector<std::uint32_t> numbers;
    std::istringstream iss(in);

    uint32_t n;

    while (iss >> n) {
        numbers.push_back(n);
    }

    return numbers;
}

}
