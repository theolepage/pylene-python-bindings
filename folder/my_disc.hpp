#pragma once

#include "se.hpp"

namespace pln {
    class my_disc : public se_t
    {
    public:
        explicit my_disc(int rad) : radius(rad)
        {}

        int get_radius() const
        {
            return radius;
        }

    private:
        int radius;

        void polymorphic() const noexcept override
        {}
    };
}