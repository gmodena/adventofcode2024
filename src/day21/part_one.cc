module;

#include <ranges>
#include <queue>
#include <unordered_map>
#include <cstdint>

export module part_one;

using namespace std;

namespace part_one {
    struct position {
    size_t row;
    size_t col;
    char prev_move;
    auto operator<=>(const position&) const = default;
};

struct vertex {
    size_t distance;
    position pos;
    size_t length;
    char output = '\0';
    bool operator<(const vertex& other) const { return distance > other.distance; }
};
};

template<>
struct std::hash<part_one::position> {
    size_t operator()(const part_one::position& p) const {
        return std::hash<size_t>{}(p.row) ^ 
               (std::hash<size_t>{}(p.col) << 1) ^ 
               (std::hash<char>{}(p.prev_move) << 2);
    }
};

template<>
struct std::hash<std::tuple<char, char, size_t>> {
    size_t operator()(const std::tuple<char, char, size_t>& t) const {
        const auto& [c1, c2, s] = t;
        return std::hash<char>{}(c1) ^ (std::hash<char>{}(c2) << 1) ^ (std::hash<size_t>{}(s) << 2);
    }
};

template<>
struct std::hash<std::tuple<part_one::position, size_t>> {
    size_t operator()(const std::tuple<part_one::position, size_t>& t) const {
        const auto& [pos, len] = t;
        return std::hash<part_one::position>{}(pos) ^ (std::hash<size_t>{}(len) << 1);
    }
};

export namespace part_one {

constexpr std::array<std::array<char, 3>, 4> pad1{{
    {'7', '8', '9'},
    {'4', '5', '6'},
    {'1', '2', '3'},
    {' ', '0', 'A'}
}};

constexpr std::array<std::array<char, 3>, 2> pad2{{
    {' ', '^', 'A'},
    {'<', 'v', '>'}
}};

using cache_t = std::unordered_map<std::tuple<char, char, size_t>, size_t>;

auto pad_move(size_t r, size_t c, char m, const auto& pad) {
    struct result { size_t row; size_t col; std::optional<char> value; };
    switch(m) {
        case '<': return result{r, c - 1, std::nullopt};
        case '^': return result{r - 1, c, std::nullopt};
        case '>': return result{r, c + 1, std::nullopt};
        case 'v': return result{r + 1, c, std::nullopt};
        case 'A': return result{r, c, pad[r][c]};
        default: throw std::runtime_error("Invalid move");
    }
}

auto get_start_pos(char prev_m) -> position {
    switch(prev_m) {
        case '^': return {0, 1, 'A'};
        case 'A': return {0, 2, 'A'};
        case '<': return {1, 0, 'A'};
        case 'v': return {1, 1, 'A'};
        case '>': return {1, 2, 'A'};
        default: throw std::runtime_error("Invalid move");
    }
}

auto calculate_cost(cache_t& cache, char goal, char prev_m, size_t pads) -> size_t {
    if (pads == 0) return 1;
    
    auto key = std::make_tuple(goal, prev_m, pads);
    if (auto it = cache.find(key); it != cache.end()) return it->second;

    std::priority_queue<vertex> queue;
    queue.push({0, get_start_pos(prev_m), 0, '\0'});

    while (!queue.empty()) {
        auto [dist, pos, _, out] = queue.top();
        queue.pop();

        if (out == goal) {
            cache[key] = dist;
            return dist;
        }

        for (char move : {'A', '^', '<', 'v', '>'}) {
            auto [rr, cc, x] = pad_move(pos.row, pos.col, move, pad2);
            if (rr >= pad2.size() || cc >= pad2[0].size() || pad2[rr][cc] == ' ') continue;
            if (x.has_value() && x.value() != goal && x.value() != '\0') continue;

            auto new_dist = dist + calculate_cost(cache, move, pos.prev_move, pads - 1);
            queue.push({new_dist, {rr, cc, move}, 0, x.value_or('\0')});
        }
    }
    throw std::runtime_error("No solution found");
}

auto dijkstra(cache_t& cache, std::string_view code, size_t pads) -> size_t {
    std::priority_queue<vertex> queue;
    std::unordered_map<std::tuple<position, size_t>, size_t> seen;
    
    queue.push({0, {3, 2, 'A'}, 0});

    while (!queue.empty()) {
        auto [dist, pos, len, _] = queue.top();
        queue.pop();

        if (len == code.length()) return dist;

        auto key = std::make_tuple(pos, len);
        if (auto it = seen.find(key); it != seen.end()) continue;
        seen[key] = dist;

        for (char move : {'A', '^', '<', 'v', '>'}) {
            auto [rr, cc, x] = pad_move(pos.row, pos.col, move, pad1);
            if (rr >= pad1.size() || cc >= pad1[0].size() || pad1[rr][cc] == ' ') continue;

            auto new_len = len;
            if (x.has_value()) {
                if (x.value() != code[len]) continue;
                new_len++;
            }

            auto new_dist = dist + calculate_cost(cache, move, pos.prev_move, pads);
            queue.push({new_dist, {rr, cc, move}, new_len});
        }
    }
    throw std::runtime_error("No solution found");
}

uint64_t solve(std::vector<std::string> codes, int num_robots ) {
    part_one::cache_t cache;
    uint64_t res = 0;

    for (const auto& code : codes) {
        auto num = std::stoull(code.substr(0, code.length() - 1));
        res += num * part_one::dijkstra(cache, code, num_robots);
    }

    return res;
} 
};