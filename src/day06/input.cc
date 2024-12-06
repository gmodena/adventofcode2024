module;

#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <array>
#include <cstdint>
#include <iostream>

export module input;

export namespace input {
std::string day06_small = R"(....#.....
.........#
..........
..#.......
.......#..
..........
.#..^.....
........#.
#.........
......#...)";

std::string day06_part1 = R"()";

using Position = std::pair<std::int64_t, std::int64_t>;
using Grid = std::vector<std::string>;

std::tuple<Grid, Position> parsed(std::string in) {
    std::istringstream iss((in));
    std::string line;
    Grid grid;
    Position start{-1, -1};

    std::int64_t y = 0;

    while (std::getline(iss, line)) {
        grid.push_back(line);
        if (start.first == -1) {
            auto x = line.find('^');
            if (x != std::string::npos) {
                start = {y, static_cast<int64_t>(x)};
            }
        }
        ++y;
    }

    return {grid, start};
}

}
