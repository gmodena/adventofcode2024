module;

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

export module input;

export namespace input {
std::string day23_small = R"(kh-tc
qp-kh
de-cg
ka-co
yn-aq
qp-ub
cg-tb
vc-aq
tb-ka
wh-tc
yn-cg
kh-ub
ta-co
de-co
tc-td
tb-wq
wh-td
ta-ka
td-qp
aq-cg
wq-ub
ub-vc
de-ta
wq-aq
wq-vc
wh-yn
ka-de
kh-ta
co-tc
wh-qp
tb-vc
td-yn)";

std::string day23 = R"()";

std::unordered_map<std::string, std::unordered_set<std::string>> parsed(const std::string& in) {
    std::unordered_map<std::string, std::unordered_set<std::string>> graph;
    std::istringstream stream(in);
    std::string connection;
    while (std::getline(stream, connection)) {
        auto dash_pos = connection.find('-');
        std::string a = connection.substr(0, dash_pos);
        std::string b = connection.substr(dash_pos + 1);
        graph[a].insert(b);
        graph[b].insert(a);
    }
    return graph;
}

}
