import os
import sys

sys.path.append(
    os.path.realpath(os.path.join(os.path.dirname(__file__), "../build")))

import pybind_test


class PyTest():

    def __init__(self, default=0):
        self.pb = pybind_test.Foo(default)

    def set_a(self, a):
        print("Before SetA")
        self.pb.set_a(a)
        print("After SetA")

    def get_a(self):
        print("Before GetA")
        ret = self.pb.get_a()
        print("After GetA")
        return ret


p = PyTest(15)
p.set_a(25)
print("{}".format(p.get_a()))
