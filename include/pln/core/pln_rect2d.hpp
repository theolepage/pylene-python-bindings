#pragma once

#include <mln/core/se/rect2d.hpp>

#include "se.hpp"

namespace pln {
    class pln_rect2d : public se_t
    {
    public:
        explicit pln_rect2d(int width, int height)
            : width_(width)
            , height_(height)
        {}

        int get_width() const
        {
            return width_;
        }

        int get_height() const
        {
            return height_;
        }

        mln::se::rect2d get_mln_instance() const
        {
            return mln::se::rect2d(width_, height_);
        }

    private:
        int width_;
        int height_;

        void polymorphic() const noexcept override
        {}
    };
}