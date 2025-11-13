#include <pybind11/pybind11.h>
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;
namespace fs = std::filesystem;

// Base Calculator class
class Calculator {
public:
    Calculator() {
        std::cout << "hello!" << std::endl;
    }

    virtual ~Calculator() = default;

    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        return a / b;
    }
};

// CPPFileCalculator class - replica of Python FileCalculator
class CPPFileCalculator : public Calculator {
public:
    CPPFileCalculator() : Calculator() {}

    // Using long long for very large sums (can handle up to 2^63-1)
    // This is sufficient for adding 100 million numbers
    long long sum_file(const std::string& path = "") {
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
};

PYBIND11_MODULE(_core, m, py::mod_gil_not_used(), py::multiple_interpreters::per_interpreter_gil()) {
    m.doc() = R"pbdoc(
        Calculator Package with C++ FileCalculator
        ------------------------------------------

        .. currentmodule:: calculator_pkg_ex

        .. autosummary::
           :toctree: _generate

           Calculator
           CPPFileCalculator
    )pbdoc";

    // Bind Calculator base class
    py::class_<Calculator>(m, "Calculator")
        .def(py::init<>())
        .def("add", &Calculator::add, "Add two numbers")
        .def("subtract", &Calculator::subtract, "Subtract two numbers")
        .def("multiply", &Calculator::multiply, "Multiply two numbers")
        .def("divide", &Calculator::divide, "Divide two numbers");

    // Bind CPPFileCalculator class
    py::class_<CPPFileCalculator, Calculator>(m, "CPPFileCalculator")
        .def(py::init<>())
        .def("sum_file", &CPPFileCalculator::sum_file,
             py::arg("path") = "",
             R"pbdoc(
                 Sum all numbers in a file

                 Args:
                     path: Path to the file containing numbers (one per line).
                           If empty, uses default path.

                 Returns:
                     long long: The sum of all numbers in the file
             )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
