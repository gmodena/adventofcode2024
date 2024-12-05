module;

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cstdint>
#include <map>

export module input;

export namespace input {
std::string day05 = R"(47|53
97|13
97|61
97|47
75|29
61|13
75|53
29|13
97|29
53|29
61|53
97|53
61|29
47|13
75|47
97|75
47|61
75|61
47|29
75|13
53|13

75,47,61,53,29
97,61,53,29,13
75,29,13
75,97,47,61,53
61,13,29
97,13,75,29,47)";

std::map<std::int64_t, std::set<std::int64_t>> parse_rules(const std::string& in) {
    std::map<std::int64_t, std::set<std::int64_t>> rules;
    std::istringstream iss(in);
    std::string line;

    while (std::getline(iss, line)) {
        if (line.empty()) break;

        size_t sep = line.find('|');
        if (sep != std::string::npos) {
            int before = std::stoi(line.substr(0, sep));
            int after = std::stoi(line.substr(sep + 1));
            rules[before].insert(after);
        }
    }


    return rules;
}

std::vector<std::vector<std::int64_t>> parse_page_orders(const std::string& in) {
    std::vector<std::vector<std::int64_t>> orders;
    std::istringstream iss(in);
    std::string line;

    bool parsing = false;
    while (std::getline(iss, line)) {
        if (line.empty()) {
            parsing = true;
            continue;
        }

        if (parsing) {
            std::istringstream vs(line);
            std::string number;
            std::vector<std::int64_t> order;

            while (std::getline(vs, number, ',')) {
                order.push_back(std::stoi(number));
            }

            orders.push_back(order);
        }
    }

    return orders;
}
}
