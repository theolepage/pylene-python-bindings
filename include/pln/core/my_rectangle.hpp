#pragma once

#include "se.hpp"

namespace pln {
    class my_rectangle : public se_t
    {
    public:
        explicit my_rectangle(int width, int height) : width_(width), height_(height)
        {}

        int get_width() const
        {
            return width_;
        }

        int get_height() const
        {
            return height_;
        }

    private:
        int width_;
        int height_;

        void polymorphic() const noexcept override {}
    };
}