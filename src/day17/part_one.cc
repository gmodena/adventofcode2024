module;

#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdint>
#include <unordered_map>

import input;

export module part_one;

export namespace part_one {

enum Opcode : uint8_t {
    ADV = 0,
    BXL = 1,
    BST = 2,
    JNZ = 3,
    BXC = 4,
    OUT = 5,
    BDV = 6,
    CDV = 7
};

int64_t combo_value(const input::Registers& regs, uint8_t operand) {
    switch (operand) {
        case 0: case 1: case 2: case 3: return operand;
        case 4: return regs.a;
        case 5: return regs.b;
        case 6: return regs.c;
    }
}

std::vector<std::int64_t>  run(const std::vector<uint8_t>& program, input::Registers& regs) {
    size_t ip = 0;
    size_t step = 2;
    std::vector<std::int64_t> output;
    while (ip + 1 < program.size()) {
        uint8_t opcode = program[ip];
        uint8_t operand = program[ip + 1];

        switch (opcode) {
            case ADV: {
                int64_t denominator = std::pow(2, combo_value(regs, operand));
                regs.a /= denominator;
                break;
            }
            case BXL: {
                regs.b ^= operand;
                break;
            }
            case BST: {
                regs.b = combo_value(regs, operand) % 8;
                break;
            }
            case JNZ: {
                if (regs.a != 0) {
                    ip = operand;
                    continue;
                }
                break;
            }
            case BXC: {
                regs.b ^= regs.c;
                break;
            }
            case OUT: {
                output.push_back(combo_value(regs, operand) % 8);
                break;
            }
            case BDV: {
                int64_t denominator = std::pow(2, combo_value(regs, operand));
                regs.b = regs.a / denominator;
                break;
            }
            case CDV: {
                int64_t denominator = std::pow(2, combo_value(regs, operand));
                regs.c = regs.a / denominator;
                break;
            }
        }

        ip += step;
    }

    return output;
}


std::string solve(std::vector<uint8_t> program, input::Registers regs) {
    auto output = run(program, regs);

    std::ostringstream oss;
    for (auto it = output.begin(); it != output.end(); ++it) {
        if (it != output.begin()) oss << ",";
        oss << *it;
    }

    return oss.str();
}
}
