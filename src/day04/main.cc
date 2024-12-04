#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    std::cout << part_one::count_xmas(input::parsed(input::day04)) << "\n";
    std::cout << part_two::count_xmas(input::parsed(input::day04)) << "\n";

}
