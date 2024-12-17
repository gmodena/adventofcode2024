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

struct Registers {
    int64_t a = 0;
    int64_t b = 0;
    int64_t c = 0;
};

Registers day17_small_regs  {729, 0, 0};
std::vector<std::uint8_t> day17_small_program = {0,1,5,4,3,0};

Registers day17_regs = {};
std::vector<std::uint8_t>  day17_program = {};
}
