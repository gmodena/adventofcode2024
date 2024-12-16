module;

#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <cstdint>
#include <tuple>
#include <iostream>

using namespace std;

export module input;

export namespace input {
std::string day16_small = R"(###############
#.......#....E#
#.#.###.#.###.#
#.....#.#...#.#
#.###.#####.#.#
#.#.#.......#.#
#.#.#####.###.#
#...........#.#
###.#.#####.#.#
#...#.....#.#.#
#.#.#.###.#.#.#
#.....#...#.#.#
#.###.#.#.#.#.#
#S..#.....#...#
###############)";

std::string day16 = R"()";

vector<string> parsed(string in) {
    vector<string> grid;
    istringstream iss((in));
    string line;

    while (getline(iss, line)) {
        grid.push_back(line);
    }
    return grid;    
}

}
