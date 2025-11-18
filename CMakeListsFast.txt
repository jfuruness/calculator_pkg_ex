# Require CMake 3.15+ and use policies up to CMake 4.0
cmake_minimum_required(VERSION 3.15...4.0)

# Project metadata comes from scikit-build-core
project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX
)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Release optimizations by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# Enable Link-Time Optimization (LTO)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)

# Find pybind11 and Python
find_package(pybind11 CONFIG REQUIRED)

# Build the Python extension module
python_add_library(_core MODULE
  src/cpp/main.cpp
  src/cpp/src/Calculator.cpp
  src/cpp/src/CPPFileCalculator.cpp
  WITH_SOABI
)

# Include directories for headers
target_include_directories(_core PRIVATE src/cpp/include)

# Link pybind11 headers
target_link_libraries(_core PRIVATE pybind11::headers)

# High-performance compiler flags
target_compile_options(_core PRIVATE
  -O3
  -march=native      # use all CPU features (for local builds)
  -ffast-math        # unsafe but fast FP optimization
)

# Remove debug checks in optimized builds
target_compile_definitions(_core PRIVATE
  VERSION_INFO=${PROJECT_VERSION}
  NDEBUG
)

# Install into the wheel under the package name
install(TARGETS _core DESTINATION calculator_pkg_ex)
