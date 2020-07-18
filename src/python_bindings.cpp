/**
 * @file python_bindings.cpp
 *
 * @brief Main entry point of the library which binds the python functions.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;
static constexpr auto PYARR_PARAMS = py::array::c_style | py::array::forcecast;

#include "py_se.hpp"
#include "py_morpho.hpp"

/** Bind supported methods, for a single type T, to a Pybind class.
 *
 * @tparam T The type used to template the methods to bind.
 * @param e Pybind class on which methods are going to be binded.
 */
template <typename T>
static void bind_type(auto&& e)
{
   e.def_static("dilation", &py_morpho::dilation<T>);
   e.def_static("erosion", &py_morpho::erosion<T>);
   e.def_static("opening", &py_morpho::opening<T>);
   e.def_static("closing", &py_morpho::closing<T>);
}

/** Bind supported methods, for a multiple types T, to a Pybind class.
 *
 * @tparam T The types used to template the methods to bind.
 * @param e Pybind class on which methods are going to be binded.
 */
template <typename ...T>
static void bind_types(auto&& e)
{
    // A simple list-initlizer expansion trick to bind multiple types.
    // For <int, float, double> for example will unpack to:
    //      {0, (bind<int>(e), 0), (bind<float>(e), 0), (bind<double>(e), 0)}
    //      Where (bind, 0) meaning bind is called and 0 is returned.
    //      The result thus will be : int _[] = {0, 0, 0, 0}.
    int _[] = {0, (bind_type<T>(e), 0)...};

    // Avoid compiler warning telling _ is not used.
    (void)_;
}

/** Bind Pybind classes, py_se and py_morpho, to apply morphological operations
 *  on numpy arrays and create Pylene structuring elements through Python.
 */
PYBIND11_MODULE(pylene, m)
{
    m.doc() = "Python bindings for Pylene, a C++ image processing library.";

    py::class_<py_se>(m, "se")
        .def_static("disc", &py_se::create_disc)
        .def_static("mask", &py_se::create_mask2d)
        .def_static("rectangle",
                    &py_se::create_rect2d,
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