module;

#include <ranges>
#include <vector>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <cstdint>

export module input;

namespace {
const std::string day03 = R"(xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5)))";
}

export namespace input {
std::string parsed() {
    return day03;
}
}
