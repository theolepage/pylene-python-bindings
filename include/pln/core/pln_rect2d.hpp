/**
 * @file pln_rect2d.hpp
 *
 * @brief Class representing a 2D rectangle structuring element.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#pragma once

#include <mln/core/se/rect2d.hpp>

#include "se.hpp"

namespace pln {
    class pln_rect2d : public se_t
    {
    public:
        /** Constructor of class pln_rect2d.
         *
         * @param width The width of the rectangle mask.
         * @param height The width of the rectangle mask.
         */
        explicit pln_rect2d(int width, int height)
            : width_(width)
            , height_(height)
        {}

        /** Return an mln::se::rect2d created from this instance.
         *
         * @returns A mln::se::rect2d similar to this instance.
         */
        mln::se::rect2d get_mln_instance() const
        {
            return mln::se::rect2d(width_, height_);
        }

    private:
        // The width of the rectangle mask.
        int width_;

        // The height of the rectangle mask.
        int height_;

        void polymorphic() const noexcept override
        {}
    };
}