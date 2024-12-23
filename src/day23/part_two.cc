module;

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>
#include <algorithm>

import input;

export module part_two;

export namespace part_two {
void find_cliques(
    const std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
    std::set<std::string> current_clique,
    std::set<std::string> remaining_nodes,
    std::vector<std::set<std::string>>& cliques) {
    
    if (remaining_nodes.empty()) {
        if (!current_clique.empty()) {
            cliques.push_back(current_clique);
        }
        return;
    }
    
    std::set<std::string> nodes_to_process = remaining_nodes;  // Make a copy
    for (const auto& node : nodes_to_process) {
        bool can_add_to_clique = true;
        for (const auto& clique_node : current_clique) {
            if (graph.at(node).count(clique_node) == 0) {
                can_add_to_clique = false;
                break;
            }
        }
        
        if (can_add_to_clique) {
            std::set<std::string> new_clique = current_clique;
            new_clique.insert(node);
            
            std::set<std::string> new_remaining;
            for (const auto& rem_node : remaining_nodes) {
                if (rem_node != node && graph.at(node).count(rem_node) > 0) {
                    new_remaining.insert(rem_node);
                }
            }
            
            find_cliques(graph, new_clique, new_remaining, cliques);
        }
        
        remaining_nodes.erase(node);
    }
}

std::set<std::string> find_largest_clique(
    const std::unordered_map<std::string, std::unordered_set<std::string>>& graph) {
    
    if (graph.empty()) {
        return {};
    }
    
    std::vector<std::set<std::string>> cliques;
    std::set<std::string> all_nodes;
    for (const auto& [node, _] : graph) {
        all_nodes.insert(node);
    }
    
    
    find_cliques(graph, {}, all_nodes, cliques);
    
    std::set<std::string> largest_clique;
    for (const auto& clique : cliques) {
        if (clique.size() > largest_clique.size()) {
            largest_clique = clique;
        }
    }
    
    return largest_clique;
}

std::string solve(std::unordered_map<std::string, std::unordered_set<std::string>> graph) {
    auto largest_clique = find_largest_clique(graph);

    std::vector<std::string> sorted_clique(largest_clique.begin(), largest_clique.end());
    std::sort(sorted_clique.begin(), sorted_clique.end());

    std::string password;
    for (size_t i = 0; i < sorted_clique.size(); ++i) {
        password += sorted_clique[i];
        if (i < sorted_clique.size() - 1) {
            password += ",";
        }
    }
    return password;
}
}
