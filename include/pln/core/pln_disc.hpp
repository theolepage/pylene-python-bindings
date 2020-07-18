/**
 * @file pln_disc.hpp
 *
 * @brief Class representing a disc structuring element.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#pragma once

#include <mln/core/se/disc.hpp>

#include "se.hpp"

namespace pln {
    class pln_disc : public se_t
    {
    public:
        /** Constructor of class pln_disc.
         *
         * @param rad The radius of the disc.
         */
        explicit pln_disc(int radius) : radius_(radius)
        {}

        /** Return an mln::se::disc created from this instance.
         *
         * @returns A mln::se::disc similar to this instance.
         */
        mln::se::disc get_mln_instance() const
        {
            return mln::se::disc(radius_);
        }

    private:
        // The radius of the disc.
        int radius_;

        void polymorphic() const noexcept override
        {}
    };
}