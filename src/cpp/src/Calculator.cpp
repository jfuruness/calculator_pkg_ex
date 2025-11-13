#include "Calculator.h"

Calculator::Calculator() {
    std::cout << "hello!" << std::endl;
}

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    return a / b;
}
