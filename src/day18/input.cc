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

using namespace std;
export namespace input {


string day18_small = R"(5,4
4,2
4,5
3,0
2,1
6,3
2,4
1,5
0,6
3,3
2,6
5,1
1,2
5,5
2,5
6,5
1,4
0,4
6,4
1,1
6,1
1,0
0,5
1,6
2,0)";
string day18 = R"()";

using coord_t = pair<int, int>; 

vector<coord_t> parsed(const string in) {
    vector<coord_t> bytes;
    stringstream ss(in);
    string line;

    while (getline(ss, line)) {
        stringstream ss(line);
        string part;
        vector<string> parts;

        while (getline(ss, part, ',')) {
            parts.push_back(part);
        }

        if (parts.size() >= 2) {
            int x = stoi(parts[1]);
            int y = stoi(parts[0]);
            bytes.emplace_back(x, y);
        }
    }

    return bytes;
}
}
