/**
 * @file se.hpp
 *
 * @brief Abstract parent class of pln::disc, pln::rect2d and pln::mask2d.
 *
 * @author Aymeric Fages
 * @author Nicolas Blin
 * @author Pierrick Made
 * @author Theo Lepage
 * @author Youssef Benkirane
 *
 */

#pragma once

/**
 * The following abstract class is used to do a type erasure on our
 * structuring elements (pln::disc, pln::rect2d and pln::mask2d).
 * The idea is to represent them as a pln::set_t and then retrieve their
 * original type with a dynamic cast.
 */
namespace pln {
    class se_t
    {
    private:
        // Used to allow the dynamic cast
        virtual void polymorphic() const noexcept
        {}
    };
}