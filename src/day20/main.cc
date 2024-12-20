#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto [grid, start, goal] = input::parsed(input::day20_small);
    std::cout << part_one::solve(grid, start, goal) << "\n";
    std::cout << part_two::solve(grid, start, goal) << "\n";
}
