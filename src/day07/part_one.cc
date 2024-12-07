module;

#include <vector>
#include <map>
#include <cstdint>
#include <functional>

import input;

export module part_one;

export namespace part_one {

std::int64_t evaluate_expression(const std::vector<std::int64_t>& values, const std::vector<char>& operators) {
    std::int64_t result = values[0];
    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '+') {
            result += values[i + 1];
        } else if (operators[i] == '*') {
            result *= values[i + 1];
        }
    }
    return result;
}

bool can_solve(std::int64_t target, const std::vector<std::int64_t>& values, size_t index, std::vector<char>& operators) {
    if (index == values.size() - 1) {
        return evaluate_expression(values, operators) == target;
    }

    operators.push_back('+');
    if (can_solve(target, values, index + 1, operators)) {
        return true;
    }
    operators.pop_back();

    operators.push_back('*');
    if (can_solve(target, values, index + 1, operators)) {
        return true;
    }
    operators.pop_back();

    return false;
}


std::int64_t solve(const std::map<std::int64_t, std::vector<std::int64_t>>& equations) {
    std::int64_t sum = 0;

    for (const auto& [target, values] : equations) {
        std::vector<char> operators;
        if (can_solve(target, values, 0, operators)) {
            sum += target;
        }
    }

    return sum;
}
}
