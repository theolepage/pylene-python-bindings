/**
 * @file numpy_convert.hpp
 *
 * @brief Utilities functions to convert a numpy array to a
 *        mln::ndbuffer_image and vice-versa.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#pragma once

#include <iostream>
#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image_format.hpp>

/** Convert a numpy array to a mln::ndbuffer_image.
 *
 * A 3D numpy array is going to be considered as a 2D RGB image.
 *
 * @tparam T The type of the py::array_t values.
 * @param array The input array representing a numpy array.
 *
 * @returns The resulting mln::ndbuffer_image.
 *
 * @throws std::runtime_error Thrown if input image shape is not supported.
 */
template <typename T>
mln::ndbuffer_image numpy_to_ndbuffer(py::array_t<T> array)
{
    py::buffer_info info = array.request();

    int ndim = info.ndim;

    if (!(ndim == 2 || (ndim == 3 && info.shape[2] == 3)))
        throw std::runtime_error("The input image dimension is \
                                  not supported.");

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

/** Convert a mln::ndbuffer_image to a numpy array.
 *
 * A mln::ndbuffer_image with a sample type of RGB values is going to be
 * converted to a 3D numpy array.
 *
 * @tparam T The type of the mln::ndbuffer_image values.
 * @param buffer The input mln::ndbuffer_image.
 *
 * @returns The resulting py::array_t.
 *
 * @throws std::runtime_error Thrown if input buffer shape is not supported.
 */
template <typename T>
py::array_t<T> ndbuffer_to_numpy(mln::ndbuffer_image buffer)
{
    int ndim = buffer.pdim();
    int new_ndim = ndim;

    if (ndim != 2)
        throw std::runtime_error("The input buffer dimension is \
                                  not supported.");

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