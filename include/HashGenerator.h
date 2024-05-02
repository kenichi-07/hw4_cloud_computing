// HashGenerator.h
#ifndef HASHGENERATOR_H
#define HASHGENERATOR_H

#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <functional>

extern "C" {
    #include "blake3.h"
}

class HashGenerator {
public:
    HashGenerator(int num_threads);
    std::vector<unsigned char> generateHashes(const std::string& input);

private:
    int num_threads;
    std::mutex mutex;
    void hashPart(const std::string& input, std::vector<unsigned char>& output, int start, int end);
};

#endif // HASHGENERATOR_H
