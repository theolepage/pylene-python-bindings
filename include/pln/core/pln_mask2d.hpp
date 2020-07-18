/**
 * @file pln_mask2d.hpp
 *
 * @brief Class representing a 2D mask structuring element.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#pragma once

#include <mln/core/se/mask2d.hpp>

#include "se.hpp"

namespace pln {
    class pln_mask2d : public se_t
    {
    public:
        // The type containing the mask values: a 2D initializer_list of int.
        using mask_t = std::initializer_list<std::initializer_list<int>>;

        /** Constructor of class pln_mask2d.
         *
         * @param mask The values of the mask.
         */
        explicit pln_mask2d(mask_t& mask) : mask_(mask)
        {}

        /** Return an mln::se::mask2d created from this instance.
         *
         * @returns A mln::se::mask2d similar to this instance.
         */
        mln::se::mask2d get_mln_instance() const
        {
            return mln::se::mask2d(mask_);
        }

    private:
        // The mask values.
        mask_t mask_;

        void polymorphic() const noexcept override
        {}
    };
}