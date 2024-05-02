// HashGenerator.cpp
#include "HashGenerator.h"

HashGenerator::HashGenerator(int num_threads) : num_threads(num_threads) {}

std::vector<unsigned char> HashGenerator::generateHashes(const std::string& input) {
    std::vector<unsigned char> hash(BLAKE3_OUT_LEN * num_threads);
    std::vector<std::thread> threads;

    int part_len = input.length() / num_threads;
    for (int i = 0; i < num_threads; ++i) {
        int start = i * part_len;
        int end = (i == num_threads - 1) ? input.length() : start + part_len;
        threads.emplace_back(&HashGenerator::hashPart, this, input, std::ref(hash), start, end);
    }

    for (auto& th : threads) {
        th.join();
    }

    return hash;
}

void HashGenerator::hashPart(const std::string& input, std::vector<unsigned char>& output, int start, int end) {
    std::string part_input = input.substr(start, end - start);
    blake3_hasher hasher;
    blake3_hasher_init(&hasher);
    blake3_hasher_update(&hasher, part_input.data(), part_input.size());
    blake3_hasher_finalize(&hasher, &output[start * BLAKE3_OUT_LEN], BLAKE3_OUT_LEN);
}
