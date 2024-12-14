module;

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <tuple>
#include <array>
#include <numeric>
#include <algorithm>

using namespace std;

export module input;

export namespace input {
string day14_small = R"(p=0,4 v=3,-3
p=6,3 v=-1,-3
p=10,3 v=-1,2
p=2,0 v=2,-1
p=0,0 v=1,3
p=3,0 v=-2,-2
p=7,6 v=-1,-3
p=3,0 v=-1,-2
p=9,3 v=2,3
p=7,3 v=-1,2
p=2,4 v=2,-3
p=9,5 v=-3,-3)";
uint64_t day14_small_w = 11;
uint64_t day14_small_h = 7;

string day14 = R"()";
uint64_t day14_w = 0;
uint64_t day14_h = 0;


struct Point {
    int64_t x;
    int64_t y;
};

struct Robot {
    Point pos;
    Point velocity;
};


vector<Robot> parsed(string in) {
    regex re(R"(p=(-?[0-9]+),(-?[0-9]+) v=(-?[0-9]+),(-?[0-9]+))");
    smatch match;
    vector<Robot> robots;

    istringstream iss(in);
    string line;
    while (std::getline(iss, line)) {
        if (regex_match(line, match, re)) {
            robots.push_back(Robot{
                Point{stoll(match[1]), stoll(match[2])},
                Point{stoll(match[3]), stoll(match[4])}
            });
        }
    }
    return robots;
}

}
