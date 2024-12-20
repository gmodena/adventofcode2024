module;

#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <ranges>
#include <iterator>

import input;
import part_one;

export module part_two;

using namespace std;

export namespace part_two {
using coord_t = pair<int, int>; 

string solve(vector<coord_t> bytes, size_t cnt, size_t w) {
    vector<vector<char>> grid(w, vector<char>(w, '.'));
 
    auto result = ranges::find_if(bytes, [&](const coord_t& cell) {
        auto [y, x] = cell;
        grid[y][x] = '#';

        auto temp_grid = grid;
        int shortest_path = part_one::dijkstra(temp_grid, w);

        return shortest_path == -1;
    });

    if (result != bytes.end()) {
        auto [y, x] = *result;
        return to_string(x) + "," + to_string(y);
    }
}

}
