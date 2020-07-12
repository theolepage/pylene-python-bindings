#include <iostream>

#include "numpy_convert.hxx"

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

class morpho
{
public:
    static
    py::array_t<double, py::array::c_style | py::array::forcecast>
    dilation(py::array_t<double, py::array::c_style | py::array::forcecast> array)
    {
        auto ndbuffer_image = numpy_to_ndbuffer(array);

        std::cout << "function: dilation" << std::endl; // FIXME

        return ndbuffer_to_numpy(ndbuffer_image);
    }

    // To-Do: erosion, opening, closing
};

PYBIND11_MODULE(pylene, m)
{
    m.doc() = "Python bindings for Pylene library";

    py::class_<morpho>(m, "morpho")
        .def_static("dilation", &morpho::dilation);
}