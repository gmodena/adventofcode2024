module;

#include <sstream>
#include <vector>
#include <string>
#include <tuple>

export module input;

export namespace input {
using Position = std::pair<int, int>;
using Path = std::vector<Position>;
using Grid = std::vector<std::string>;

std::string day20_small = R"(###############
#...#...#.....#
#.#.#.#.#.###.#
#S#...#.#.#...#
#######.#.#.###
#######.#.#...#
#######.#.###.#
###..E#...#...#
###.#######.###
#...###...#...#
#.#####.#.###.#
#.#...#.#.#...#
#.#.#.#.#.#.###
#...#...#...###
###############)";

std::string day20 = R"()";

std::tuple<Grid, Position, Position> parsed(const std::string& input) {
    Grid grid;
    Position start, goal;
    std::istringstream iss(input);
    std::string line;
    int row = 0;

    while (std::getline(iss, line)) {
        grid.push_back(line);
        for (int col = 0; col < line.size(); ++col) {
            char c = line[col];
            if (c == 'S') {
                start = {row, col};
            } else if (c == 'E') {
                goal = {row, col};
            }
        }
        ++row;
    }

    return {grid, start, goal};
}

}
