module;

#include <vector>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <string>

import input;

export module part_one;

using namespace std;

export namespace part_one {
using Position = std::pair<int, int>;
using Path = std::vector<Position>;
using Grid = std::vector<std::string>;

constexpr int SAVE_DISTANCE = 100;

std::vector<Position> distance(const Position& pos, int max_distance) {
    std::set<Position> points;

    for (int i = 0; i <= max_distance; ++i) {
        int x = i, y = max_distance - i;
        points.insert({pos.first + x, pos.second + y});
        points.insert({pos.first - x, pos.second - y});
        points.insert({pos.first + x, pos.second - y});
        points.insert({pos.first - x, pos.second + y});
    }

    return {points.begin(), points.end()};
}

Path bfs(const Grid& grid, const Position& start, const Position& goal) {
    std::deque<Path> queue{{{start}}};
    std::set<Position> visited{start};

    auto is_valid = [&](const Position& pos) {
        return pos.first >= 0 && pos.first < grid.size() &&
               pos.second >= 0 && pos.second < grid[0].size() &&
               grid[pos.first][pos.second] != '#' && visited.find(pos) == visited.end();
    };

    while (!queue.empty()) {
        Path path = queue.front();
        queue.pop_front();
        Position node = path.back();

        if (node == goal) {
            return path;
        }

        for (const auto& neighbor : distance(node, 1)) {
            if (is_valid(neighbor)) {
                visited.insert(neighbor);
                path.push_back(neighbor);
                queue.push_back(path);
            }
        }
    }

    return {};
}

int solve(const Grid& grid, const Position& start, const Position& goal) {
    Path path = bfs(grid, start, goal);
    std::map<Position, int> path_map;
    for (size_t i = 0; i < path.size(); ++i) {
        path_map[path[i]] = static_cast<int>(i);
    }

    int count = 0;

    for (size_t i = 0; i < path.size(); ++i) {
        const auto& pos = path[i];
        for (const auto& neighbor : distance(pos, 2)) {
            auto it = path_map.find(neighbor);
            if (it != path_map.end() && it->second - static_cast<int>(i) - 2 >= SAVE_DISTANCE) {
                ++count;
            }
        }
    }

    return count;
}
}
