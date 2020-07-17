#pragma once

#include <mln/core/se/disc.hpp>

#include "se.hpp"

namespace pln {
    class pln_disc : public se_t
    {
    public:
        explicit pln_disc(int rad) : radius_(rad)
        {}

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