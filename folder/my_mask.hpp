#pragma once

#include "se.hpp"

#include <vector>
namespace pln {
    class my_mask : public se_t
    {
    public:
        using mask_t = std::vector<std::vector<int>>;

        explicit my_mask(mask_t&& m) : mask_(m)
        {}

        const mask_t& get_mask() const
        {
            return mask_;
        }

    private:
        mask_t mask_;

        void polymorphic() const noexcept override
        {}
    };
}