/**
 * @file py_morpho.hpp
 *
 * @brief Class, accessible through Python, to call Pylene mathematical
 *        morphology operators.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#pragma once

#include "numpy_convert.hpp"

#include "../include/pln/core/morpho.hpp"

/**
 * Class, accessible through Python, which provides static functions to apply
 * a dilation, an erosion, an opening and a closing on a py::array_t<T>.
 * Every function takes also a py_se as the second parameter and returns a
 * new py::array_t<T>.
 */
class py_morpho
{
public:
    /** Apply a morphological dilation on a numpy array.
     *
     * @tparam T The type of the py::array_t values.
     * @param array The input array representing a numpy array.
     * @param se A instance of py_se pointing to a pln structuring element.
     *
     * @returns The output py::array_t<T> after the operation.
     */
    template <typename T>
    static py::array_t<T> dilation(py::array_t<T, PYARR_PARAMS> array, py_se se)
    {
        auto image = numpy_to_ndbuffer<T>(array);
        auto res = pln::dilation<T>(image, se.get_se().get());
        return ndbuffer_to_numpy<T>(res);
    }

    /** Apply a morphological erosion on a numpy array.
     *
     * @tparam T The type of the py::array_t values.
     * @param array The input array representing a numpy array.
     * @param se A instance of py_se pointing to a pln structuring element.
     *
     * @returns The output py::array_t<T> after the operation.
     */
    template <typename T>
    static py::array_t<T> erosion(py::array_t<T, PYARR_PARAMS> array, py_se se)
    {
        auto ndbuffer_image = numpy_to_ndbuffer<T>(array);
        auto res = pln::erosion<T>(ndbuffer_image, se.get_se().get());
        return ndbuffer_to_numpy<T>(res);
    }

     /** Apply a morphological opening on a numpy array.
     *
     * @tparam T The type of the py::array_t values.
     * @param array The input array representing a numpy array.
     * @param se A instance of py_se pointing to a pln structuring element.
     *
     * @returns The output py::array_t<T> after the operation.
     */
    template <typename T>
    static py::array_t<T> opening(py::array_t<T, PYARR_PARAMS> array, py_se se)
    {
        auto ndbuffer_image = numpy_to_ndbuffer<T>(array);
        auto res = pln::opening<T>(ndbuffer_image, se.get_se().get());
        return ndbuffer_to_numpy<T>(res);
    }

     /** Apply a morphological closing on a numpy array.
     *
     * @tparam T The type of the py::array_t values.
     * @param array The input array representing a numpy array.
     * @param se A instance of py_se pointing to a pln structuring element.
     *
     * @returns The output py::array_t<T> after the operation.
     */
    template <typename T>
    static py::array_t<T> closing(py::array_t<T, PYARR_PARAMS> array, py_se se)
    {
        auto ndbuffer_image = numpy_to_ndbuffer<T>(array);
        auto res = pln::closing<T>(ndbuffer_image, se.get_se().get());
        return ndbuffer_to_numpy<T>(res);
    }
};