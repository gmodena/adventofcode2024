#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto levels = input::parsed();
    std::cout << part_one::is_safe(levels) << "\n";
    std::cout << part_two::is_safe(levels) << "\n";

}
