module;

#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdint>
#include <algorithm>

import input;

export module part_two;

export namespace part_two {
std::int64_t can_obstruct(const input::Grid& grid, input::Position start, input::Position obstruction) {
    constexpr std::array<input::Position, 4> directions = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    
    input::Position current = start;
    std::int64_t dir_index = 0;
    
    std::set<input::Position> visited_positions;
    std::set<std::pair<input::Position, int>> visited_states;
    
    visited_positions.insert(current);
    visited_states.insert({current, dir_index});
    
    
    while (true) {
        input::Position next = {
            current.first + directions[dir_index].first,
            current.second + directions[dir_index].second
        };
        
        if (next.first < 0 || next.first >= grid.size() ||
            next.second < 0 || next.second >= grid[0].size())
            break;
        else if (grid[next.first][next.second] == '#' || next == obstruction)
        {
            dir_index = (dir_index + 1) % 4;
        } else {
            current = next;
            
            if (visited_states.count({current, dir_index}) == 0) {
                visited_positions.insert(current);
                visited_states.insert({current, dir_index});
            } else {
                return true;
            }
        }
    }
    
    return false;
}

// FIXME: refactor part1 solver; do better than brute forcing all positions.
std::int64_t solve(const input::Grid& grid, input::Position start) {
    std::int64_t counts = 0;
    std::set<input::Position> positions;
    input::Position obstacle = {-1,-1};
    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[0].size(); ++y) {
            obstacle = {x,y};
            if (obstacle != start && can_obstruct(grid, start, obstacle)) {
                ++counts;
            }
        }
    }
    return counts;    
}
}
