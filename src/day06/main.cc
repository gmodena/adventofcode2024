#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto [grid, start] = input::parsed(input::day06_small);
    std::cout << part_one::solve(grid, start) << "\n";
    std::cout << part_two::solve(grid, start) << "\n";

}
