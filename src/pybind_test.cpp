#include <iostream>
#include <string>
#include <vector>
#ifndef UNIT_TEST
#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#else

#endif

void example(std::vector<std::string> my_list) {
  for (auto s : my_list) {
    std::cout << s << std::endl;
  }
}

void hello(std::vector < std::string >> a) { return; }

#ifndef UNIT_TEST
PYBIND11_MODULE(pybind_test, m) {
  m.doc() = "Example Pybind 11 plugin";
  m.def("example", &example,
        "A function that prints a list of strings to stdout");
}
#else
int main(int argc, char **argv) {
  std::vector<std::string> l = {"Hello"

                                "World"};
  example(l);
}
#endif
