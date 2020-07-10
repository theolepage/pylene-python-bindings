#include <pybind11/pybind11.h>

// To-Do: Implement a function creating a mln::ndbuffer_image from a numpy array
//        https://pybind11.readthedocs.io/en/stable/advanced/pycpp/numpy.html

int add(int i, int j)
{
    return i + j;
}

PYBIND11_MODULE(pylene, m)
{
    m.doc() = "Python bindings for Pylene library";

    m.def("add", &add, "A function which adds two numbers");
}