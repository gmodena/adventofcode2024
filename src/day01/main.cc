#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    auto [left_list, right_list] = input::parsed();
    std::cout << part_one::pair_numbers(left_list, right_list) << "\n";
    std::cout << part_two::similarity_score(left_list, right_list) << "\n";

}
