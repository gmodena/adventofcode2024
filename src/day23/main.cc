#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto graph = input::parsed(input::day23_small);
    std::cout << part_one::solve(graph) << "\n";
    std::cout << part_two::solve(graph) << "\n";
}
