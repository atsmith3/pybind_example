cmake_minimum_required(VERSION 3.15)
MESSAGE(STATUS "CMAKE_ROOT: " ${CMAKE_ROOT})

project(pybind VERSION 1.0.0 LANGUAGES CXX)

#set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_BUILD_TYPE "DEBUG")

set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -O0 -g")

set(PYBIND_ROOT /home/andrew/prj/pybind11/.venv/lib/python3.12/site-packages/pybind11)
set(PYBIND_INCLUDE_DIR ${PYBIND_ROOT}/include)
set(PYTHON_INCLUDE_DIR /usr/include/python3.12)

set(PRJ_CPP
  ./src/pybind_test.cpp
)

set(PRJ_INCLUDE_DIR
  ./src/
)

include_directories(${PRJ_INCLUDE_DIR} ${PYBIND_INCLUDE_DIR} ${PYTHON_INCLUDE_DIR})

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
add_library(pybind_test.cpython-312-x86_64-linux-gnu SHARED ${PRJ_CPP})

enable_testing()

add_executable(pybind_unit ${PRJ_CPP})
target_compile_definitions(pybind_unit PUBLIC -DUNIT_TEST)

add_test(ut.hello ./pybind_unit)
add_test(ut.hello.valgrind ./pybind_unit)

add_test(it.hello python3 ../test/test.py)

