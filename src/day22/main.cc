#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto secrets = input::parsed(input::day22_small);
    std::cout << part_one::solve(secrets) << "\n";
    std::cout << part_two::solve(secrets) << "\n";
}
