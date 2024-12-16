module;

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <limits>
#include <tuple>


import part_one;

using namespace std;

export module part_two;

export namespace part_two {
    int solve(vector<string> grid) {

    auto [score, counts] = part_one::search(grid);

    return counts;
}
}
