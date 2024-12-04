module;

#include <ranges>
#include <vector>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <cstdint>

export module input;

export namespace input {
std::string day03_part1 = R"(xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5)))";
std::string day03_part2 = R"(xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5)))";
}
