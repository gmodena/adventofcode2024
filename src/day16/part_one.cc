module;

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <limits>
#include <tuple>

import input;

using namespace std;

export module part_one;

export namespace part_one {

using coord_t = pair<int, int>;

struct coord_hash {
    size_t operator()(const coord_t& c) const {
        return hash<int>()(c.first) ^ (hash<int>()(c.second) << 1);
    }
};

struct vertex_hash {
    size_t operator()(const pair<coord_t, coord_t>& s) const {
        coord_hash hash_fn;
        return hash_fn(s.first) ^ (hash_fn(s.second) << 1);
    }
};

struct vertex_t {
    int score;
    coord_t loc;
    coord_t face;
    vector<coord_t> path;

    bool operator>(const vertex_t& other) const {
        return score > other.score;
    }
};

pair<int, int> search(const vector<string>& grid) {
    constexpr int turn_cost = 1000;
    constexpr int move_cost = 1;
    vector<coord_t> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    unordered_map<coord_t, char, coord_hash> maze;
    coord_t start, end;

    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            coord_t pos = {x, y};
            maze[pos] = grid[y][x];
            if (grid[y][x] == 'S') start = pos;
            if (grid[y][x] == 'E') end = pos;
        }
    }

    priority_queue<vertex_t, vector<vertex_t>, greater<>> queue;
    unordered_map<pair<coord_t, coord_t>, int, vertex_hash> visited;
    unordered_set<coord_t, coord_hash> best_path;
    int low_score = numeric_limits<int>::max();

    queue.push({0, start, {1, 0}, {start}});

    while (!queue.empty()) {
        auto [score, loc, face, path] = queue.top();
        queue.pop();

        if (score > low_score) break;

        if (loc == end) {
            if (score < low_score) best_path.clear();
            low_score = score;
            best_path.insert(path.begin(), path.end());
            continue;
        }

        visited[{loc, face}] = score;

        for (const auto& d : directions) {
            coord_t next_loc = {loc.first + d.first, loc.second + d.second};
            if (maze.find(next_loc) == maze.end() || maze[next_loc] == '#') continue;

            int cost = (d != face) ? (turn_cost + move_cost) : move_cost;
            if (visited.find({next_loc, d}) == visited.end() || visited[{next_loc, d}] > score + cost) {
                auto new_path = path;
                new_path.push_back(next_loc);
                queue.push({score + cost, next_loc, d, new_path});
            }
        }
    }

    return {low_score, static_cast<int>(best_path.size())};
}

int solve(vector<string> grid) {
    auto [score, counts] = search(grid);

    return score;
}
}
