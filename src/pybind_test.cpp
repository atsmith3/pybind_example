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

class Foo {
private:
  int _a;

public:
  Foo(int a = 0) : _a(a){};
  ~Foo(){};

  void set_a(const int new_a) { this->_a = new_a; }
  int get_a() const { return this->_a; }
};

#ifndef UNIT_TEST
PYBIND11_MODULE(pybind_test, m) {
  pybind11::class_<Foo>(m, "Foo")
      .def(pybind11::init<int>())
      .def("set_a", &Foo::set_a)
      .def("get_a", &Foo::get_a);
}
#else
int main(int argc, char **argv) {
  Foo *test = new Foo(10);
  std::cout << test->get_a() << std::endl;
  test->set_a(20);
  std::cout << test->get_a() << std::endl;
}
#endif
