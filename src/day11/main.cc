#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    std::cout << part_one::solve(input::day11_small, 25) << "\n";
    std::cout << part_one::solve(input::day11_small, 75) << "\n";
}
