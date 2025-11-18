#ifndef CPPFILECALCULATOR_H
#define CPPFILECALCULATOR_H

#include "Calculator.h"
#include <string>

// CPPFileCalculator class - replica of Python FileCalculator
class CPPFileCalculator : public Calculator {
public:
    CPPFileCalculator();

    // Using long long for very large sums (can handle up to 2^63-1)
    // This is sufficient for adding 100 million numbers
    long long sum_file(const std::string& path = "");
};

#endif // CPPFILECALCULATOR_H
