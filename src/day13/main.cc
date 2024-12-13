#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto equations = input::parsed(input::day13_small);
    std::cout << part_one::solve(equations, 0) << "\n";
    std::cout << part_one::solve(equations, 10000000000000) << "\n";
}
