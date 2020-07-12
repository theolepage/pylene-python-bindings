#pragma once

#include "numpy_convert.hxx"

class py_morpho
{
public:
    template <typename T>
    static py::array_t<T> dilation(py::array_t<T, py_array_params> array, py_se)
    {
        auto ndbuffer_image = numpy_to_ndbuffer<T>(array);
        // pln::dilation(ndbuffer_image, pln::my_disc(1));
        return ndbuffer_to_numpy<T>(ndbuffer_image);
    }
};