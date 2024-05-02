#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <vector>
#include <string> // Make sure this is included if you use std::string

class FileWriter {
public:
    FileWriter(int num_threads, int memory_size);
    void writeHashesToFile(const std::vector<unsigned char>& hashes, const std::string& filename = "hashes.bin");
private:
    int num_threads;
    int memory_size; // in MB
};

// Implementation in FileWriter.cpp
FileWriter::FileWriter(int num_threads, int memory_size) : num_threads(num_threads), memory_size(memory_size) {}

#endif // FILEWRITER_H