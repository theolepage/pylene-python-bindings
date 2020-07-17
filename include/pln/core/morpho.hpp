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
            throw std::runtime_error("Not supported se_t type");               \
    }                                                                          \
    while (false)

namespace pln {
    template <typename T>
    mln::ndbuffer_image dilation(mln::ndbuffer_image image, se_t* se)
    {
        mln::ndbuffer_image res;

        if (image.sample_type() == mln::sample_type_id::RGB8)
        {
            auto* image_ = image.cast_to<mln::rgb8, 2>();
            if (image_ == nullptr)
                throw std::runtime_error("Not supported input image");

            DISPATCH_ACCORDING_TO_SE(mln::morpho::dilation);
            return res;
        }

        auto* image_ = image.cast_to<T, 2>();
        if (image_ == nullptr)
            throw std::runtime_error("Not supported input image");

        DISPATCH_ACCORDING_TO_SE(mln::morpho::dilation);
        return res;
    }

    template <typename T>
    mln::ndbuffer_image erosion(mln::ndbuffer_image image, se_t* se)
    {
        mln::ndbuffer_image res;

        if (image.sample_type() == mln::sample_type_id::RGB8)
        {
            auto* image_ = image.cast_to<mln::rgb8, 2>();
            if (image_ == nullptr)
                throw std::runtime_error("Not supported input image");

            DISPATCH_ACCORDING_TO_SE(mln::morpho::erosion);
            return res;
        }

        auto* image_ = image.cast_to<T, 2>();
        if (image_ == nullptr)
            throw std::runtime_error("Not supported input image");

        DISPATCH_ACCORDING_TO_SE(mln::morpho::erosion);
        return res;
    }

    template <typename T>
    mln::ndbuffer_image opening(mln::ndbuffer_image image, se_t* se)
    {
        mln::ndbuffer_image res;

        if (image.sample_type() == mln::sample_type_id::RGB8)
        {
            auto* image_ = image.cast_to<mln::rgb8, 2>();
            if (image_ == nullptr)
                throw std::runtime_error("Not supported input image");

            DISPATCH_ACCORDING_TO_SE(mln::morpho::opening);
            return res;
        }

        auto* image_ = image.cast_to<T, 2>();
        if (image_ == nullptr)
            throw std::runtime_error("Not supported input image");

        DISPATCH_ACCORDING_TO_SE(mln::morpho::opening);
        return res;
    }

    template <typename T>
    mln::ndbuffer_image closing(mln::ndbuffer_image image, se_t* se)
    {
        mln::ndbuffer_image res;

        if (image.sample_type() == mln::sample_type_id::RGB8)
        {
            auto* image_ = image.cast_to<mln::rgb8, 2>();
            if (image_ == nullptr)
                throw std::runtime_error("Not supported input image");

            DISPATCH_ACCORDING_TO_SE(mln::morpho::closing);
            return res;
        }

        auto* image_ = image.cast_to<T, 2>();
        if (image_ == nullptr)
            throw std::runtime_error("Not supported input image");

        DISPATCH_ACCORDING_TO_SE(mln::morpho::closing);
        return res;
    }
}