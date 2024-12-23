module;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

import input;

export module part_one;

export namespace part_one {

std::set<std::set<std::string>> traverse(const std::unordered_map<std::string, std::unordered_set<std::string>>& graph) {
    std::set<std::set<std::string>> triads;
    for (const auto& [node, neighbors] : graph) {
        for (const auto& neighbor : neighbors) {
            for (const auto& mutual_neighbor : graph.at(neighbor)) {
                if (neighbors.count(mutual_neighbor) && node < neighbor && neighbor < mutual_neighbor) {
                    triads.insert({node, neighbor, mutual_neighbor});
                }
            }
        }
    }
    return triads;
}

int count_triads(const std::set<std::set<std::string>>& triads) {
    int count = 0;
    for (const auto& triad : triads) {
        for (const auto& computer : triad) {
            if (computer[0] == 't') {
                ++count;
                break;
            }
        }
    }
    return count;
}

int solve(std::unordered_map<std::string, std::unordered_set<std::string>> graph ) {
    auto triads = traverse(graph);

    int count = count_triads(triads);

    return count;
}

}
