#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    const auto parsed_input = input::parsed(input::day14_small);
    const auto width = input::day14_small_w;
    const auto height = input::day14_small_h;

    std::cout << part_one::solve(parsed_input, 100, width, height) << "\n";
    std::cout << part_two::solve(parsed_input, 10000, width, height) << "\n";

    return 0;
}

