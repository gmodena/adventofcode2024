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

std::string day12_small = R"(RRRRIICCFF
RRRRIICCCF
VVRRRCCFFF
VVRCCCJFFF
VVVVCJJCFE
VVIVCCJJEE
VVIIICJJEE
MIIIIIJJEE
MIIISIJEEE
MMMISSJEEE)";

std::string day12 = R"()";


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
