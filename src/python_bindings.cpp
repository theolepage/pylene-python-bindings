#include <iostream>

#include <mln/core/image/ndbuffer_image.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

mln::ndbuffer_image numpy_to_ndbuffer(py::array_t<double>)
{
    return mln::ndbuffer_image();
}

py::array_t<double> ndbuffer_to_numpy(mln::ndbuffer_image)
{
    return py::array_t<double>();
}

class morpho
{
public:
    static py::array_t<double> dilation(py::array_t<double> array)
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