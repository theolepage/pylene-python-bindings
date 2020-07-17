#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;
static const auto pyarr_params = py::array::c_style | py::array::forcecast;

#include "py_se.hxx"
#include "py_morpho.hxx"

template <typename T>
void bind_type(auto&& e)
{
   e.def_static("dilation", &py_morpho::dilation<T>);
   e.def_static("erosion", &py_morpho::erosion<T>);
   e.def_static("opening", &py_morpho::opening<T>);
   e.def_static("closing", &py_morpho::closing<T>);
}

template <typename ...T>
void bind_types(auto&& e)
{
    // A simple list-initlizer expansion trick
    // For <int, float, double> for example will unpack to:
    // {0, (bind<int>(e), 0), (bind<float>(e), 0), (bind<double>(e), 0)}
    // Where (bind, 0) meaning bind is called and 0 is returned.
    // The result thus will be : int _[] = {0, 0, 0, 0}.
    int _[] = {0, (bind_type<T>(e), 0)...};

    // Avoid compiler warning telling _ is not used.
    (void)_;
}

PYBIND11_MODULE(pylene, m)
{
    m.doc() = "Python bindings for Pylene, a C++ image processing library.";

    py::class_<py_se>(m, "se")
        .def_static("disc", &py_se::create_disc)
        .def_static("mask", &py_se::create_mask)
        .def_static("rectangle",
                    &py_se::create_rect,
                    py::arg("width"),
                    py::arg("height"));

    bind_types<bool,
               uint8_t,
               uint16_t,
               uint32_t,
               uint64_t,
               float,
               double>(py::class_<py_morpho>(m, "morpho"));
}