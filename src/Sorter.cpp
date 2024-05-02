#include "Sorter.h"
#include <algorithm>

Sorter::Sorter(int num_threads) : num_threads(num_threads) {}

void Sorter::sortHashes(std::vector<unsigned char>& hashes) {
    // If threading is implemented, this would be the place to use `num_threads`
    std::sort(hashes.begin(), hashes.end());
}
