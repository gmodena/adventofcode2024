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
std::string day08_small = R"(............
........0...
.....0......
.......0....
....0.......
......A.....
............
............
........A...
.........A..
............
............)";

std::string day08 = R"()";

using Grid = std::unordered_map<char, std::vector<std::pair<std::int64_t, std::int64_t>>>;

std::tuple<Grid, std::int64_t, std::int64_t> parsed(const std::string& in) {
    Grid grid;
    std::stringstream iss(in);
    std::string line;
    std::int64_t row = 0;
    std::int64_t col = 0;

    while (std::getline(iss, line)) {
        col = line.size();

        for (size_t i = 0; i < line.size(); ++i) {
            char cell = line[i];

            if (cell != '.') {
                grid[cell].emplace_back(row, i);
            }
        }
        ++row;
    }

    return std::make_tuple(grid, row, col);

}

}
