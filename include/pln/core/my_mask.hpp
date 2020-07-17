#pragma once

#include <mln/core/se/mask2d.hpp>

#include "se.hpp"

namespace pln {
    class my_mask : public se_t
    {
    public:
        using mask_t = std::initializer_list<std::initializer_list<int>>;

        explicit my_mask(mask_t&& m) : mask_(m)
        {}

        const mask_t& get_mask() const
        {
            return mask_;
        }

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