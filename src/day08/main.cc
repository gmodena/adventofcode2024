#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto [grid, row, col] = input::parsed(input::day08_small);
    std::cout << part_one::solve(grid, row, col) << "\n";
    std::cout << part_two::solve(grid, row, col) << "\n";
}
