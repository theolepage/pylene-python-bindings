#pragma once

#include <mln/morpho/dilation.hpp>
#include <mln/morpho/closing.hpp>
#include <mln/morpho/opening.hpp>
#include <mln/morpho/erosion.hpp>
#include <mln/core/image/ndimage.hpp>

#include <mln/core/colors.hpp>

#include <mln/core/se/private/se_facade.hpp>
#include <mln/core/concepts/structuring_element.hpp>

#include <mln/core/se/disc.hpp>
#include <mln/core/se/mask2d.hpp>
#include <mln/core/se/rect2d.hpp>

#include "se.hpp"

#define EDWIN(function) do {                                                    \
    if (image.sample_type() == mln::sample_type_id::RGB8)                       \
    {                                                                           \
        auto* image_ = (image.cast_to<mln::rgb8, 2>());                         \
        if (image_ == nullptr){                                                 \
            throw std::runtime_error("Not supported input image");}             \
                                                                                \
        if (const my_disc* const d = dynamic_cast<my_disc*>(se)){               \
            return function(*image_, d->get_mln_instance());}                   \
                                                                                \
        else if (const my_mask* const m = dynamic_cast<my_mask*>(se)){          \
            return function(*image_, m->get_mln_instance());}                   \
                                                                                \
        else if (const my_rectangle* const r = dynamic_cast<my_rectangle*>(se)){\
            return function(*image_, r->get_mln_instance());}                   \
                                                                                \
        throw std::runtime_error("Not supported se_t type");                    \
    }                                                                           \
                                                                                \
    auto* image_ = (image.cast_to<T, 2>());                                     \
    if (image_ == nullptr){                                                     \
        throw std::runtime_error("Not supported input image");}                 \
                                                                                \
    if (const my_disc* const d = dynamic_cast<my_disc*>(se)){                   \
        return function(*image_, d->get_mln_instance());}                       \
                                                                                \
    else if (const my_mask* const m = dynamic_cast<my_mask*>(se)){              \
        return function(*image_, m->get_mln_instance());}                       \
                                                                                \
    else if (const my_rectangle* const r = dynamic_cast<my_rectangle*>(se)){    \
        return function(*image_, r->get_mln_instance());}                       \
                                                                                \
    throw std::runtime_error("Not supported se_t type");                        \
    } while (false)

namespace pln {
    template <typename T>
    mln::ndbuffer_image dilation(mln::ndbuffer_image image, se_t* se)
    {
        EDWIN(mln::morpho::dilation);
    }

    template <typename T>
    mln::ndbuffer_image erosion(mln::ndbuffer_image image, se_t* se)
    {
        EDWIN(mln::morpho::erosion);
    }

    template <typename T>
    mln::ndbuffer_image opening(mln::ndbuffer_image image, se_t* se)
    {
        EDWIN(mln::morpho::opening);
    }

    template <typename T>
    mln::ndbuffer_image closing(mln::ndbuffer_image image, se_t* se)
    {
        EDWIN(mln::morpho::closing);
    }
}