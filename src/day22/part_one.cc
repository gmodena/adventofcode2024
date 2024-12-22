module;


#include <iostream>
#include <vector>
#include <cstdint>

import input;

export module part_one;

export namespace part_one {

uint32_t next_secret(uint32_t secret) {
    secret ^= (secret * 64);
    secret %= 16777216;
    secret ^= (secret / 32);
    secret %= 16777216;
    secret ^= (secret * 2048);
    secret %= 16777216;
    return secret;
}


uint32_t compute_secret(uint32_t initial_secret, uint32_t iterations) {
    uint32_t secret = initial_secret;
    for (int i = 0; i < iterations; ++i) {
        secret = next_secret(secret);
    }
    return secret;
}

uint64_t solve(std::vector<uint32_t> initial_secrets) {
    uint64_t sum = 0;

    for (uint32_t secret : initial_secrets) {
        sum += compute_secret(secret, 2000);
    }

    return sum;
}

}
