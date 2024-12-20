#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto [patterns, towels] = input::parsed(input::day19_small);
    std::cout << part_one::solve(towels, patterns) << "\n";
    std::cout << part_two::solve(towels, patterns) << "\n";
}
