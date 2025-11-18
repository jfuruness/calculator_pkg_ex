#include <pybind11/pybind11.h>
#include "Calculator.h"
#include "CPPFileCalculator.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

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
