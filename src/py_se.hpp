/**
 * @file py_se.hpp
 *
 * @brief Class, accessible through Python, to instantiate a Pylene
 *        structuring element.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#pragma once

#include "../include/pln/core/se.hpp"
#include "../include/pln/core/pln_disc.hpp"
#include "../include/pln/core/pln_rect2d.hpp"
#include "../include/pln/core/pln_mask2d.hpp"

/**
 * Class, accessible through Python, to instantiate a Pylene
 * structuring element.
 *
 * Provide static functions to create a disc, a rect2d and a mask2d. Moreover,
 * store this newly created instance of a pln::set_t to be used later.
 */
class py_se
{
public:
    /** Constructor of class py_se.
     *
     * @param se A shared pointer to an instance of pln::set_t to store.
     */
    py_se(std::shared_ptr<pln::se_t> se)
        : se_(se)
    {}

    /** Create a pln::pln_disc and store it in an instance of py_se.
     *
     * @param radius The radius of the disc to instantiate.
     *
     * @returns The newly created instance of py_se.
     */
    static py_se create_disc(int radius)
    {
        return py_se(std::make_shared<pln::pln_disc>(radius));
    }

    /** Create a pln::pln_rect2d and store it in an instance of py_se.
     *
     * @param width The width of the rect2d to instantiate.
     * @param height The width of the rect2d to instantiate.
     *
     * @returns The newly created instance of py_se.
     */
    static py_se create_rect2d(int width, int height)
    {
        return py_se(std::make_shared<pln::pln_rect2d>(width, height));
    }

    /** Create a pln::pln_mask2d and store it in an instance of py_se.
     *
     * @param mask The 2D py::array_t<int> representing the mask values.
     *
     * @returns The newly created instance of py_se.
     */
    static py_se create_mask2d(py::array_t<int, PYARR_PARAMS>)
    {
        // FIXME: Converting py::array_t to initializer_list is tricky.
        std::initializer_list<std::initializer_list<int>> l = { { 0 } };
        return py_se(std::make_shared<pln::pln_mask2d>(l));
    }

    /** Return the shared pointer pointing to a pln::set_t
     *   instance created earlier.
     *
     * @returns A shared pointer pointing to a pln::set_t.
     */
    std::shared_ptr<pln::se_t> get_se(void) const
    {
        return se_;
    }

private:
    // A shared pointer to the instance of pln::set_t to store.
    std::shared_ptr<pln::se_t> se_;
};