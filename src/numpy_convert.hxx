#pragma once

#include <iostream>
#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image_format.hpp>

template <typename T>
mln::ndbuffer_image numpy_to_ndbuffer(py::array_t<T> array)
{
    py::buffer_info info = array.request();

    int ndim = info.ndim;

    // We assume that a 3D numpy array is a Pylene 2D RGB image
    auto type = mln::sample_type_traits<T>::id();
    if (ndim == 3)
    {
        type = mln::sample_type_id::RGB8;
        ndim--;
    }

    // Determine ndbuffer_image shape
    int shape[ndim] = { 0 };
    for (auto i = 0; i < ndim; i++)
        shape[i] = info.shape[i];

    return mln::ndbuffer_image::from_buffer(static_cast<std::byte*>(info.ptr),
                                            type,
                                            ndim,
                                            shape,
                                            nullptr,
                                            true);
}

template <typename T>
py::array_t<T> ndbuffer_to_numpy(mln::ndbuffer_image buffer)
{
    int ndim = buffer.pdim();
    int new_ndim = ndim;

    if (buffer.sample_type() == mln::sample_type_id::RGB8)
        new_ndim++;

    // Determine numpy array shape
    std::vector<ssize_t> shape(new_ndim);
    for (auto i = 0; i < ndim; i++)
        shape[i] = buffer.size(i);

    // Determine numpy array strides (reverse order)
    std::vector<ssize_t> strides(new_ndim);
    for (auto i = 0; i < ndim; i++)
        strides[i] = buffer.byte_stride(ndim - 1 - i);

    if (buffer.sample_type() == mln::sample_type_id::RGB8)
    {
        shape[ndim] = 3;
        strides[ndim] = sizeof(T);
    }

    auto info = py::buffer_info(
        buffer.buffer(),
        sizeof(T),
        py::format_descriptor<T>::format(),
        new_ndim,
        shape,
        strides
    );
    return py::array_t<T>(info);
}