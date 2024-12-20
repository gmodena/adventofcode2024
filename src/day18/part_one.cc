module;

#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <ranges>
#include <iterator>
#include <limits>
#include <unordered_map>

import input;

export module part_one;

using namespace std;

export namespace part_one {
using coord_t = pair<int, int>; 

int dijkstra(const vector<vector<char>>& grid, int w) {
    const int INF = numeric_limits<int>::max();
    vector<vector<int>> dist(w, vector<int>(w, INF));
    priority_queue<pair<int, coord_t>, vector<pair<int, coord_t>>, greater<>> pq;

    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    auto in_bounds = [w](int y, int x) { return y >= 0 && x >= 0 && y < w && x < w; };

    while (!pq.empty()) {
        auto [d, coord] = pq.top();
        auto [y, x] = coord;
        pq.pop();

        if (y == w - 1 && x == w - 1) {
            return d;
        }

        if (d > dist[y][x]) {
            continue;
        }

        for (auto [dy, dx] : vector<coord_t>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int ny = y + dy, nx = x + dx;
            if (in_bounds(ny, nx) && grid[ny][nx] == '.' && d + 1 < dist[ny][nx]) {
                dist[ny][nx] = d + 1;
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }
    }

    return -1;
}

int solve(vector<coord_t> bytes, size_t cnt, size_t w) {
    vector<vector<char>> grid(w, vector<char>(w, '.'));
    
    for (size_t i = 0; i < min(cnt, bytes.size()); ++i) {
        auto [y, x] = bytes[i];
        grid[y][x] = '#';
    }
    
    return dijkstra(grid, w);
}
}
