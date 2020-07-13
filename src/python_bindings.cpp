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
        .def_static("rectangle",
                    &py_se::create_rect,
                    py::arg("width"),
                    py::arg("height"));

    py::class_<py_morpho>(m, "morpho")
        // Numpy types: https://numpy.org/devdocs/user/basics.types.html

        // .def_static("dilation", &py_morpho::dilation<bool>)
        // .def_static("dilation", &py_morpho::dilation<std::int8_t>)
        // .def_static("dilation", &py_morpho::dilation<int16_t>)
        // .def_static("dilation", &py_morpho::dilation<int32_t>)
        // .def_static("dilation", &py_morpho::dilation<int64_t>)
        .def_static("dilation", &py_morpho::dilation<uint8_t>)
        // .def_static("dilation", &py_morpho::dilation<uint16_t>)
        // .def_static("dilation", &py_morpho::dilation<uint32_t>)
        // .def_static("dilation", &py_morpho::dilation<uint64_t>)
        // .def_static("dilation", &py_morpho::dilation<float>)
        // .def_static("dilation", &py_morpho::dilation<double>)

        // .def_static("erosion", &py_morpho::erosion<bool>)
        // .def_static("erosion", &py_morpho::erosion<std::int8_t>)
        // .def_static("erosion", &py_morpho::erosion<int16_t>)
        // .def_static("erosion", &py_morpho::erosion<int32_t>)
        // .def_static("erosion", &py_morpho::erosion<int64_t>)
        .def_static("erosion", &py_morpho::erosion<uint8_t>)
        // .def_static("erosion", &py_morpho::erosion<uint16_t>)
        // .def_static("erosion", &py_morpho::erosion<uint32_t>)
        // .def_static("erosion", &py_morpho::erosion<uint64_t>)
        // .def_static("erosion", &py_morpho::erosion<float>)
        // .def_static("erosion", &py_morpho::erosion<double>)

        // .def_static("opening", &py_morpho::opening<bool>)
        // .def_static("opening", &py_morpho::opening<std::int8_t>)
        // .def_static("opening", &py_morpho::opening<int16_t>)
        // .def_static("opening", &py_morpho::opening<int32_t>)
        // .def_static("opening", &py_morpho::opening<int64_t>)
        .def_static("opening", &py_morpho::opening<uint8_t>)
        // .def_static("opening", &py_morpho::opening<uint16_t>)
        // .def_static("opening", &py_morpho::opening<uint32_t>)
        // .def_static("opening", &py_morpho::opening<uint64_t>)
        // .def_static("opening", &py_morpho::opening<float>)
        // .def_static("opening", &py_morpho::opening<double>)

        // .def_static("closing", &py_morpho::closing<bool>)
        // .def_static("closing", &py_morpho::closing<std::int8_t>)
        // .def_static("closing", &py_morpho::closing<int16_t>)
        // .def_static("closing", &py_morpho::closing<int32_t>)
        // .def_static("closing", &py_morpho::closing<int64_t>)
        .def_static("closing", &py_morpho::closing<uint8_t>);
        // .def_static("closing", &py_morpho::closing<uint16_t>)
        // .def_static("closing", &py_morpho::closing<uint32_t>)
        // .def_static("closing", &py_morpho::closing<uint64_t>)
        // .def_static("closing", &py_morpho::closing<float>)
        // .def_static("closing", &py_morpho::closing<double>);
}