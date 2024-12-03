#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto memory = input::parsed();
    std::cout << part_one::repair_memory(memory) << "\n";
    std::cout << part_two::repair_memory(memory) << "\n";

}
