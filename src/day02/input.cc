module;

#include <ranges>
#include <vector>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <cstdint>

export module input;

namespace {
const std::string_view day02 = R"(7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9)";
}

export namespace input {
std::vector<std::vector<int64_t>> parsed() {
    std::vector<std::vector<int64_t>> matrix;
    std::istringstream iss((std::string(day02)));
    std::string line;

    while (std::getline(iss, line)) {
        std::istringstream iss_line(line);
        std::vector<int64_t> row;
        int64_t val;

        while (iss_line >> val)
            row.push_back(val);

        matrix.push_back(row);
    }
    return matrix;

};
}
