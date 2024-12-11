cmake_minimum_required(VERSION 3.15...3.26)
project(${SKBUILD_PROJECT_NAME} LANGUAGES CXX)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(_core MODULE 
  src/_cpp/bindings.cpp
  src/_cpp/union_find.cpp
)


# Include directory for .hpp / .h files
target_include_directories(_core PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/_cpp
)


install(TARGETS _core DESTINATION ${SKBUILD_PROJECT_NAME})
