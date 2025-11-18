#include "CPPFileCalculator.h"
#include <fstream>
#include <iostream>

CPPFileCalculator::CPPFileCalculator() : Calculator() {}

long long CPPFileCalculator::sum_file(const std::string& path) {
    std::string file_path = path;

    // If no path provided, use default path relative to this module
    if (file_path.empty()) {
        // Default to nums.csv in the file_calculator directory
        file_path = "src/calculator_pkg_ex/file_calculator/nums.csv";
    }

    long long total = 0;
    std::ifstream file(file_path);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + file_path);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                total += std::stoll(line);
            } catch (const std::exception& e) {
                std::cerr << "Warning: Could not parse line: " << line << std::endl;
            }
        }
    }

    file.close();
    return total;
}
