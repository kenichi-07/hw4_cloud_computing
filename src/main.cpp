#include <iostream>
#include <vector>
#include <cstdlib>  // For std::atoi
#include <chrono>
#include "HashGenerator.h"
#include "Sorter.h"
#include "FileWriter.h"
#include "cpu_features.h"

int main(int argc, char* argv[]) {
    // Initialize CPU features
    _get_cpu_features();
    if (argc < 9) {
        std::cerr << "Usage: " << argv[0] 
                  << " -h <num_hash_threads> -s <num_sort_threads> -w <num_write_threads> -m <memory_size_mb>\n";
        return 1;
    }

    int num_hash_threads = 1, num_sort_threads = 1, num_write_threads = 1;
    int memory_size = 128; // Default memory size in MB

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-h" && i + 1 < argc) {
            num_hash_threads = std::atoi(argv[i + 1]);
        } else if (std::string(argv[i]) == "-s" && i + 1 < argc) {
            num_sort_threads = std::atoi(argv[i + 1]);
        } else if (std::string(argv[i]) == "-w" && i + 1 < argc) {
            num_write_threads = std::atoi(argv[i + 1]);
        } else if (std::string(argv[i]) == "-m" && i + 1 < argc) {
            memory_size = std::atoi(argv[i + 1]);
        }
    }

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    // Initialize components with the specified thread counts
    HashGenerator generator(num_hash_threads);
    Sorter sorter(num_sort_threads);
    FileWriter writer(num_write_threads, memory_size);

    // Example data
    std::string data = "Example data for hashing.";
    std::vector<unsigned char> hashes = generator.generateHashes(data);
    sorter.sortHashes(hashes);
    writer.writeHashesToFile(hashes);

    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Operation with " << num_hash_threads << " hash threads, " 
              << num_sort_threads << " sort threads, and " 
              << num_write_threads << " write threads completed successfully in " << elapsed.count() << " ms." << std::endl;
    return 0;
}
