#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "matrix.hpp"

namespace py = pybind11;

void i_do_nothing();

class morpho
{
public:
    static int dilation(py::array_t<double> array)
    {
        i_do_nothing();
        std::cout << "dilation\n";

        return 17;
    }

    // To-Do: erosion, opening, closing
};

PYBIND11_MODULE(pylene, m)
{
    m.doc() = "Python bindings for Pylene library";

    py::class_<morpho>(m, "morpho")
        .def_static("dilation", &morpho::dilation);

    // py::class_<mln::ndbuffer_image<float, 1>>(m, "Matrix", py::buffer_protocol())
    //     // Construct from a buffer, python -> c++
    //     .def(py::init([](py::buffer const b)
    //     {
    //         py::buffer_info info = b.request();
    //         py::print("hello", info.format, info.ndim, info.shape);
    //         // if (info.format != py::format_descriptor<float>::format() || info.ndim != 2)
    //         //     throw std::runtime_error("Incompatible buffer format!");

    //         // auto v = new Matrix(info.shape[0], info.shape[1]);
    //         // memcpy(v->data(), info.ptr, sizeof(float) * (size_t) (v->rows() * v->cols()));
    //         // return v;
    //     }));

    // py::class_<Matrix>(m, "Matrix", py::buffer_protocol())
    //     // Construct from a buffer, python -> c++
    //     .def(py::init([](py::buffer const b)
    //     {
    //         py::buffer_info info = b.request();
    //         if (info.format != py::format_descriptor<float>::format() || info.ndim != 2)
    //             throw std::runtime_error("Incompatible buffer format!");

    //         auto v = new Matrix(info.shape[0], info.shape[1]);
    //         memcpy(v->data(), info.ptr, sizeof(float) * (size_t) (v->rows() * v->cols()));
    //         return v;
    //     }));
}