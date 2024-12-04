module;

#include <ranges>
#include <vector>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <cstdint>

export module input;

export namespace input {
std::string day04 = R"(MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX)";

std::vector<std::string> parsed(std::string in) {
    std::vector<std::string> grid;
    std::istringstream iss((in));
    std::string line;

    while (std::getline(iss, line)) {
        grid.push_back(line);
    }
    return grid;    
}

}
