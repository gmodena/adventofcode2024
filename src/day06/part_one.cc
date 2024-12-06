module;

#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdint>
#include <algorithm>

import input;

export module part_one;

export namespace part_one {

std::int64_t solve(const input::Grid& grid, input::Position start) {
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
        else if (grid[next.first][next.second] == '#')
        {
            dir_index = (dir_index + 1) % 4;
        } else {
            current = next;
            
            if (visited_states.count({current, dir_index}) == 0) {
                visited_positions.insert(current);
                visited_states.insert({current, dir_index});
            }
        }
    }
    
    return static_cast<std::int64_t>(visited_positions.size());
}

}
