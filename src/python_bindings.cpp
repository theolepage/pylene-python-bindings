#include <pybind11/pybind11.h>

#include "matrix.hpp"

namespace py = pybind11;

int add(int i, int j)
{
    py::print(1, 2.0, "three");
    return i + j;
}

PYBIND11_MODULE(pylene, m)
{
    m.doc() = "Python bindings for Pylene library";

    // m.def("add", &add, "A function which adds two numbers");

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

    py::class_<Matrix>(m, "Matrix", py::buffer_protocol())
        // Construct from a buffer, python -> c++
        .def(py::init([](py::buffer const b)
        {
            py::buffer_info info = b.request();
            if (info.format != py::format_descriptor<float>::format() || info.ndim != 2)
                throw std::runtime_error("Incompatible buffer format!");

            auto v = new Matrix(info.shape[0], info.shape[1]);
            memcpy(v->data(), info.ptr, sizeof(float) * (size_t) (v->rows() * v->cols()));
            return v;
        }));
}