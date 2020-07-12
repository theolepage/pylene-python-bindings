#pragma once

#include <iostream>
#include <mln/core/image/ndbuffer_image.hpp>

template <typename T>
mln::ndbuffer_image numpy_to_ndbuffer(py::array_t<T> array)
{
    py::buffer_info info = array.request();

    // FIXME: For some reason omitting this line causes a segfault.
    py::format_descriptor<T>::format();

    int ndim = info.ndim;

    // Determine ndbuffer_image shape
    int shape[ndim] = { 0 };
    for (auto i = 0; i < ndim; i++)
        shape[i] = info.shape[i];

    // Determine ndbuffer_image strides
    std::ptrdiff_t byte_strides[] = { 0 };
    for (auto i = 0; i < ndim; i++)
        byte_strides[i] = info.strides[ndim - 1 - i];

    return mln::ndbuffer_image::from_buffer(static_cast<std::byte*>(info.ptr),
                                            mln::sample_type_id::DOUBLE,
                                            ndim,
                                            shape,
                                            byte_strides,
                                            false);
}

template <typename T>
py::array_t<T> ndbuffer_to_numpy(mln::ndbuffer_image buffer)
{
    int ndim = buffer.pdim();

    // Determine numpy array shape
    std::vector<ssize_t> shape;
    for (auto i = 0; i < ndim; i++)
        shape.push_back(buffer.size(i));

    // Determine numpy array strides
    std::vector<ssize_t> strides;
    for (auto i = ndim - 1; i >= 0; i--)
        strides.push_back(buffer.byte_stride(i));

    auto info = py::buffer_info(
        buffer.buffer(),
        sizeof(T),
        py::format_descriptor<T>::format(),
        ndim,
        shape,
        strides
    );
    return py::array_t<T>(info);
}