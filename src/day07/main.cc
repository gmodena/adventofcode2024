#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto equations = input::parsed(input::day07_small);
    std::cout << part_one::solve(equations) << "\n";
    std::cout << part_two::solve(equations) << "\n";
}
