module;

#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
#include <regex>

using namespace std;

export module input;

export namespace input {
std::string day13_small = R"(Button A: X+94, Y+34
Button B: X+22, Y+67
Prize: X=8400, Y=5400

Button A: X+26, Y+66
Button B: X+67, Y+21
Prize: X=12748, Y=12176

Button A: X+17, Y+86
Button B: X+84, Y+37
Prize: X=7870, Y=6450

Button A: X+69, Y+23
Button B: X+27, Y+71
Prize: X=18641, Y=10279)";

string day13 = R"()";

vector<vector<uint64_t>> parsed(const string& input) {
    vector<vector<uint64_t>> result;
    regex number_regex("-?\\d+");
    sregex_iterator it(input.begin(), input.end(), number_regex);
    sregex_iterator end;

    while (it != end) {
        vector<uint64_t> current_group;
        for (int i = 0; i < 6 && it != end; ++i, ++it) {
            current_group.push_back(stoull(it->str()));
        }
        
        if (current_group.size() == 6) {
            result.push_back(current_group);
        }
    }

    return result;
}

}
