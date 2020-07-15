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

namespace pln {
    // template <class SE>
    // mln::details::StructuringElement<SE> test(se_t* se)
    // {
    //     if (const my_disc* const d = dynamic_cast<my_disc*>(se))
    //     {
    //         return mln::se::disc(d->get_radius());
    //     }
    //     else if (const my_mask* const m = dynamic_cast<my_mask*>(se))
    //     {
    //         return mln::se::mask2d(m->get_mask());
    //     }
    //     else if (const my_rectangle* const r = dynamic_cast<my_rectangle*>(se))
    //     {
    //         return mln::se::rect2d(r->get_width(), r->get_height());
    //     }
    //     throw std::runtime_error("Not supported se_t type");
    // }

    template <typename T>
    mln::ndbuffer_image dilation(mln::ndbuffer_image image, se_t* se)
    {
        auto* image_ = (image.cast_to<T, 2>());

        if (const my_disc* const d = dynamic_cast<my_disc*>(se))
        {
            return mln::morpho::dilation(*image_,
                                         mln::se::disc(d->get_radius()));
        }
        else if (const my_mask* const m = dynamic_cast<my_mask*>(se))
        {
            return mln::morpho::dilation(*image_,
                                         mln::se::mask2d(m->get_mask()));
        }
        else if (const my_rectangle* const r = dynamic_cast<my_rectangle*>(se))
        {
            return mln::morpho::dilation(*image_,
                                         mln::se::rect2d(r->get_width(),
                                                         r->get_height()));
        }
        throw std::runtime_error("Not supported se_t type");
    }

    template <typename T>
    mln::ndbuffer_image erosion(mln::ndbuffer_image image, se_t* se)
    {
        auto* image_ = (image.cast_to<T, 2>());

        if (const my_disc* const d = dynamic_cast<my_disc*>(se))
        {
            return mln::morpho::erosion(*image_,
                                         mln::se::disc(d->get_radius()));
        }
        else if (const my_mask* const m = dynamic_cast<my_mask*>(se))
        {
            return mln::morpho::erosion(*image_,
                                         mln::se::mask2d(m->get_mask()));
        }
        else if (const my_rectangle* const r = dynamic_cast<my_rectangle*>(se))
        {
            return mln::morpho::erosion(*image_,
                                         mln::se::rect2d(r->get_width(),
                                                         r->get_height()));
        }
        throw std::runtime_error("Not supported se_t type");
    }

    template <typename T>
    mln::ndbuffer_image opening(mln::ndbuffer_image image, se_t* se)
    {
        auto* image_ = (image.cast_to<T, 2>());

        if (const my_disc* const d = dynamic_cast<my_disc*>(se))
        {
            return mln::morpho::opening(*image_,
                                         mln::se::disc(d->get_radius()));
        }
        else if (const my_mask* const m = dynamic_cast<my_mask*>(se))
        {
            return mln::morpho::opening(*image_,
                                         mln::se::mask2d(m->get_mask()));
        }
        else if (const my_rectangle* const r = dynamic_cast<my_rectangle*>(se))
        {
            return mln::morpho::opening(*image_,
                                         mln::se::rect2d(r->get_width(),
                                                         r->get_height()));
        }
        throw std::runtime_error("Not supported se_t type");
    }

    template <typename T>
    mln::ndbuffer_image closing(mln::ndbuffer_image image, se_t* se)
    {
        auto* image_ = (image.cast_to<T, 2>());

        if (const my_disc* const d = dynamic_cast<my_disc*>(se))
        {
            return mln::morpho::closing(*image_,
                                         mln::se::disc(d->get_radius()));
        }
        else if (const my_mask* const m = dynamic_cast<my_mask*>(se))
        {
            return mln::morpho::closing(*image_,
                                         mln::se::mask2d(m->get_mask()));
        }
        else if (const my_rectangle* const r = dynamic_cast<my_rectangle*>(se))
        {
            return mln::morpho::closing(*image_,
                                         mln::se::rect2d(r->get_width(),
                                                         r->get_height()));
        }
        throw std::runtime_error("Not supported se_t type");
    }
}