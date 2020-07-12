#include <iostream>

#include <mln/core/image/ndbuffer_image.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

// - [ ] Check necessary copy
// - [ ] C-style
// - [ ] Pass strides to from_buffer
// - [ ] Template

mln::ndbuffer_image numpy_to_ndbuffer(py::array_t<double> array)
{
    py::buffer_info info = array.request();
    if (info.format != py::format_descriptor<double>::format())
        throw std::runtime_error("Invalid buffer type.");

    int shape[info.ndim] = { 0 };
    for (auto i = 0; i < info.ndim; i++)
        shape[i] = info.shape[i];

    // static_cast<std::byte*>(info.ptr)
    // mln::sample_type_id::DOUBLE
    // info.ndim
    // shape
    // nullptr
    // false
    return mln::ndbuffer_image::from_buffer(static_cast<std::byte*>(info.ptr),
                                            mln::sample_type_id::DOUBLE,
                                            info.ndim,
                                            shape,
                                            nullptr,
                                            false);
}

py::array_t<double> ndbuffer_to_numpy(mln::ndbuffer_image buffer)
{
    int ndim = buffer.pdim();

    std::vector<ssize_t> shape;
    for (auto i = 0; i < ndim; i++)
        shape.push_back(buffer.size(i));

    std::vector<ssize_t> strides;
    for (auto i = ndim - 1; i >= 0; i--)
        strides.push_back(buffer.byte_stride(i));

    auto info = py::buffer_info(
        buffer.buffer(),
        sizeof(double),
        py::format_descriptor<double>::format(),
        ndim,
        shape,
        strides
    );

    return py::array_t<double>(info);
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