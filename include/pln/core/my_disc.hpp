#pragma once

#include <mln/core/se/disc.hpp>

#include "se.hpp"

namespace pln {
    class my_disc : public se_t
    {
    public:
        explicit my_disc(int rad) : radius_(rad)
        {}

        int get_radius() const
        {
            return radius_;
        }

        mln::se::disc get_mln_instance() const
        {
            return mln::se::disc(radius_);
        }

    private:
        int radius_;

        void polymorphic() const noexcept override
        {}
    };
}