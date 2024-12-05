#include <iostream>

import part_one;
import part_two;
import input;

int main() {
    std::cout << part_one::count_mid(input::parse_rules(input::day05), input::parse_page_orders(input::day05)) << "\n";
    std::cout << part_two::count_mid(input::parse_rules(input::day05), input::parse_page_orders(input::day05)) << "\n";

}
