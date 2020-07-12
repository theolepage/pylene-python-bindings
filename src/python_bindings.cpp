#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

static const auto py_array_params = py::array::c_style | py::array::forcecast;

#include "py_se.hxx"
#include "py_morpho.hxx"

PYBIND11_MODULE(pylene, m)
{
    m.doc() = "Python bindings for Pylene library.";

    py::class_<py_se>(m, "se")
        .def_static("disc", &py_se::create_disc)
        .def_static("mask", &py_se::create_mask)
        .def_static("rectangle", &py_se::create_rect,
                    py::arg("width"), py::arg("height"));

    py::class_<py_morpho>(m, "morpho")
        // Numpy types: https://numpy.org/devdocs/user/basics.types.html

        .def_static("dilation", &py_morpho::dilation<int8_t>)
        .def_static("dilation", &py_morpho::dilation<int16_t>)
        .def_static("dilation", &py_morpho::dilation<int32_t>)
        .def_static("dilation", &py_morpho::dilation<int64_t>)

        .def_static("dilation", &py_morpho::dilation<uint8_t>)
        .def_static("dilation", &py_morpho::dilation<uint16_t>)
        .def_static("dilation", &py_morpho::dilation<uint32_t>)
        .def_static("dilation", &py_morpho::dilation<uint64_t>)

        .def_static("dilation", &py_morpho::dilation<float>)
        .def_static("dilation", &py_morpho::dilation<double>);
}