#include <iostream>
#include <fstream>
#include "FileWriter.h"

void FileWriter::writeHashesToFile(const std::vector<unsigned char>& hashes, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        for (auto hash : hashes) {
            file.write(reinterpret_cast<const char*>(&hash), sizeof(hash));
        }
        file.close();
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}
