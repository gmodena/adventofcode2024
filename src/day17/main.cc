#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto regs = input::day17_small_regs;
    auto program = input::day17_small_program;
    std::cout << part_one::solve(program, regs) << "\n";
}
