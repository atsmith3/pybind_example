import os
import sys
sys.path.append(os.path.realpath(os.path.join(os.path.dirname(__file__),"../build")))
import pybind_test

pybind_test.example(["Hello", "World"])
