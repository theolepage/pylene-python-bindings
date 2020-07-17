#pragma once

#include "numpy_convert.hxx"

#include "../include/pln/core/morpho.hpp"

class py_morpho
{
public:
    template <typename T>
    static py::array_t<T> dilation(py::array_t<T, pyarr_params> array, py_se se)
    {
        auto image = numpy_to_ndbuffer<T>(array);
        auto res = pln::dilation<T>(image, se.get_se().get());
        return ndbuffer_to_numpy<T>(res);
    }

    template <typename T>
    static py::array_t<T> erosion(py::array_t<T, pyarr_params> array, py_se se)
    {
        auto ndbuffer_image = numpy_to_ndbuffer<T>(array);
        auto res = pln::erosion<T>(ndbuffer_image, se.get_se().get());
        return ndbuffer_to_numpy<T>(res);
    }

    template <typename T>
    static py::array_t<T> opening(py::array_t<T, pyarr_params> array, py_se se)
    {
        auto ndbuffer_image = numpy_to_ndbuffer<T>(array);
        auto res = pln::opening<T>(ndbuffer_image, se.get_se().get());
        return ndbuffer_to_numpy<T>(res);
    }

    template <typename T>
    static py::array_t<T> closing(py::array_t<T, pyarr_params> array, py_se se)
    {
        auto ndbuffer_image = numpy_to_ndbuffer<T>(array);
        auto res = pln::closing<T>(ndbuffer_image, se.get_se().get());
        return ndbuffer_to_numpy<T>(res);
    }
};