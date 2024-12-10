module;

#include <string>
#include <sstream>
#include <cstdint>
#include <vector>

using namespace std;

export module input;

export namespace input {

std::string day10_small = R"(89010123
78121874
87430965
96549874
45678903
32019012
01329801
10456732)";


std::string day10 = R"()";

vector<vector<int64_t>> parsed(const string& in) {
    vector<vector<int64_t>> grid;
    istringstream stream(in);
    string line;

    while (getline(stream, line)) {
        vector<int64_t> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        grid.push_back(row);
    }

    return grid;
}

}
