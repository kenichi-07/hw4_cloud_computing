#ifndef SORTER_H
#define SORTER_H

#include <vector>

class Sorter {
public:
    explicit Sorter(int num_threads);  // Add a constructor that takes an integer
    void sortHashes(std::vector<unsigned char>& hashes);

private:
    int num_threads;  // Store the number of threads (if needed for threading)
};

#endif // SORTER_H
