/**
 * @file morpho.hpp
 *
 * @brief Functions to apply mathematical morphology operators on a
 *        mln::ndbuffer_image according to a given structuring element.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#pragma once

#include <mln/core/image/ndimage.hpp>
#include <mln/core/colors.hpp>
#include <mln/morpho/dilation.hpp>
#include <mln/morpho/closing.hpp>
#include <mln/morpho/opening.hpp>
#include <mln/morpho/erosion.hpp>

#include "pln_disc.hpp"
#include "pln_rect2d.hpp"
#include "pln_mask2d.hpp"

/** Even though using the define directive of the preprocessor is usually a
 *  bad practice, in this situation it allows us to avoid code duplication.
 *  After many attempts, we were not able to factorize the following code
 *  in a C++ function as the return type cannot be deduced.
 *  Indeed, the parent class of all structuring elements is templated.
 */
#define DISPATCH_ACCORDING_TO_SE(function)                                     \
    do                                                                         \
    {                                                                          \
        if (const pln_disc* const d = dynamic_cast<pln_disc*>(se))             \
            res = function(*image_, d->get_mln_instance());                    \
                                                                               \
        else if (const pln_mask2d* const m = dynamic_cast<pln_mask2d*>(se))    \
            res = function(*image_, m->get_mln_instance());                    \
                                                                               \
        else if (const pln_rect2d* const r = dynamic_cast<pln_rect2d*>(se))    \
            res = function(*image_, r->get_mln_instance());                    \
                                                                               \
        else                                                                   \
            throw std::runtime_error("This structuring element is \
                                      not supported.");                        \
    }                                                                          \
    while (false)

namespace pln {
    /** Apply a morphological dilation on a mln::ndbuffer_image.
     *
     * @tparam T The type of the mln::ndbuffer_image values.
     * @param image The input image on which the dilation will be applied.
     * @param se The structuring element used for the dilation.
     *
     * @returns The resulting mln::ndbuffer_image after the dilation is applied.
     *
     * @throws std::runtime_error Thrown if image or se is not supported.
     *
     */
    template <typename T>
    mln::ndbuffer_image dilation(mln::ndbuffer_image image, se_t* se)
    {
        mln::ndbuffer_image res;

        if (image.sample_type() == mln::sample_type_id::RGB8)
        {
            auto* image_ = image.cast_to<mln::rgb8, 2>();
            if (image_ == nullptr)
                throw std::runtime_error("The input image dimension is \
                                          not supported.");

            DISPATCH_ACCORDING_TO_SE(mln::morpho::dilation);
            return res;
        }

        auto* image_ = image.cast_to<T, 2>();
        if (image_ == nullptr)
            throw std::runtime_error("The input image dimension is \
                                      not supported.");

        DISPATCH_ACCORDING_TO_SE(mln::morpho::dilation);
        return res;
    }

    /** Apply a morphological erosion on a mln::ndbuffer_image.
     *
     * @tparam T The type of the mln::ndbuffer_image values.
     * @param image The input image on which the erosion will be applied.
     * @param se The structuring element used for the erosion.
     *
     * @returns The resulting mln::ndbuffer_image after the erosion is applied.
     *
     * @throws std::runtime_error Thrown if image or se is not supported.
     *
     */
    template <typename T>
    mln::ndbuffer_image erosion(mln::ndbuffer_image image, se_t* se)
    {
        mln::ndbuffer_image res;

        if (image.sample_type() == mln::sample_type_id::RGB8)
        {
            auto* image_ = image.cast_to<mln::rgb8, 2>();
            if (image_ == nullptr)
                throw std::runtime_error("The input image dimension is \
                                          not supported.");

            DISPATCH_ACCORDING_TO_SE(mln::morpho::erosion);
            return res;
        }

        auto* image_ = image.cast_to<T, 2>();
        if (image_ == nullptr)
            throw std::runtime_error("The input image dimension is \
                                      not supported.");

        DISPATCH_ACCORDING_TO_SE(mln::morpho::erosion);
        return res;
    }

    /** Apply a morphological opening on a mln::ndbuffer_image.
     *
     * @tparam T The type of the mln::ndbuffer_image values.
     * @param image The input image on which the opening will be applied.
     * @param se The structuring element used for the opening.
     *
     * @returns The resulting mln::ndbuffer_image after the opening is applied.
     *
     * @throws std::runtime_error Thrown if image or se is not supported.
     *
     */
    template <typename T>
    mln::ndbuffer_image opening(mln::ndbuffer_image image, se_t* se)
    {
        mln::ndbuffer_image res;

        if (image.sample_type() == mln::sample_type_id::RGB8)
        {
            auto* image_ = image.cast_to<mln::rgb8, 2>();
            if (image_ == nullptr)
                throw std::runtime_error("The input image dimension is \
                                          not supported.");

            DISPATCH_ACCORDING_TO_SE(mln::morpho::opening);
            return res;
        }

        auto* image_ = image.cast_to<T, 2>();
        if (image_ == nullptr)
            throw std::runtime_error("The input image dimension is \
                                      not supported.");

        DISPATCH_ACCORDING_TO_SE(mln::morpho::opening);
        return res;
    }

    /** Apply a morphological closing on a mln::ndbuffer_image.
     *
     * @tparam T The type of the mln::ndbuffer_image values.
     * @param image The input image on which the closing will be applied.
     * @param se The structuring element used for the closing.
     *
     * @returns The resulting mln::ndbuffer_image after the closing is applied.
     *
     * @throws std::runtime_error Thrown if image or se is not supported.
     *
     */
    template <typename T>
    mln::ndbuffer_image closing(mln::ndbuffer_image image, se_t* se)
    {
        mln::ndbuffer_image res;

        if (image.sample_type() == mln::sample_type_id::RGB8)
        {
            auto* image_ = image.cast_to<mln::rgb8, 2>();
            if (image_ == nullptr)
                throw std::runtime_error("The input image dimension is \
                                          not supported.");

            DISPATCH_ACCORDING_TO_SE(mln::morpho::closing);
            return res;
        }

        auto* image_ = image.cast_to<T, 2>();
        if (image_ == nullptr)
            throw std::runtime_error("The input image dimension is \
                                      not supported.");

        DISPATCH_ACCORDING_TO_SE(mln::morpho::closing);
        return res;
    }
}