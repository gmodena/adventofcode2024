#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto bytes = input::parsed(input::day18_small);
    std::cout << part_one::solve(bytes, 12, 7) << "\n";
    std::cout << part_two::solve(bytes, 12, 7) << "\n";
}
