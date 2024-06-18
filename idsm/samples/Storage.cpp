#include <iostream>
#include <fstream>
#include <vector>

void storeVectorInFile(const std::vector<uint8_t>& vec, const std::string& fileName) {
    std::ofstream outFile(fileName, std::ios::out | std::ios::app | std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(vec.data()), vec.size());

    // Add a delimiter at the end of each vector
    char delimiter = '\n'; // Use any delimiter you like
    outFile.write(&delimiter, sizeof(char));

    outFile.close();
}

std::vector<std::vector<uint8_t>> getAllVectorsFromFile(const std::string& fileName) {
    std::vector<std::vector<uint8_t>> vectors;
    
    std::ifstream inFile(fileName, std::ios::in | std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading." << std::endl;
        return vectors;
    }

    std::vector<uint8_t> vec;
    char delimiter;

    while (inFile.read(reinterpret_cast<char*>(&delimiter), sizeof(char))) {
        if (delimiter == '\n') {
            vectors.push_back(vec);
            vec.clear();
        } else {
            vec.push_back(static_cast<uint8_t>(delimiter));
        }
    }

    inFile.close();

    return vectors;
}

int main() {
    // Example vectors to store
    std::vector<std::vector<uint8_t>> vectors = {
        {0x01, 0x02, 0x03,0x01, 0x02, 0x03},
        {0x11, 0x22, 0x33},
        {0x44, 0xAA, 0xBB,0x01, 0x02, 0x03},
        {0xCC, 0xDD, 0xEE}
    };

    // Store all vectors in the file
    for (const auto& vec : vectors) {
        storeVectorInFile(vec, "vectors.bin");
    }

    // Retrieve all vectors stored in the file
    std::vector<std::vector<uint8_t>> retrievedVectors = getAllVectorsFromFile("vectors.bin");

    // Display the retrieved vectors
    for (const auto& vec : retrievedVectors) {
        for (const auto& val : vec) {
            std::cout << std::hex << static_cast<int>(val) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}