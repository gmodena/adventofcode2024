#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto grid = input::parsed(input::day12_small);
    std::cout << part_one::solve(grid) << "\n";
   // std::cout << part_two::solve(grid) << "\n";
}
