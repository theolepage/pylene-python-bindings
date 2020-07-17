#pragma once

#include <mln/core/se/mask2d.hpp>

#include "se.hpp"

namespace pln {
    class pln_mask2d : public se_t
    {
    public:
        using mask_t = std::initializer_list<std::initializer_list<int>>;

        explicit pln_mask2d(mask_t& m) : mask_(m)
        {}

        mln::se::mask2d get_mln_instance() const
        {
            return mln::se::mask2d(mask_);
        }

    private:
        mask_t mask_;

        void polymorphic() const noexcept override
        {}
    };
}