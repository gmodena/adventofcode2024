#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto schematics = input::parsed(input::day25_small);
    std::cout << part_one::solve(schematics) << "\n";
}
