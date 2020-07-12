#include "se.hpp"

#include <mln/core/se/disc.hpp>
#include <mln/core/se/mask2d.hpp>
#include <mln/core/se/rectangle.hpp>

#include "my_disc.hpp"
#include "my_mask.hpp"
#include "my_rectangle.hpp"

namespace pln {
    auto se_t::get_structuring_element() const
    {
        if (const my_disc* const d = dynamic_cast<my_disc*>(this))
        {
            return mln::se::disc(d->get_radius());
        }
        else if (const my_mask* const m = dynamic_cast<my_mask*>(this))
        {
            return mln::se::mask2d(m->get_mask());
        }
        else if (const my_rectangle* const r = dynamic_cast<my_mask*>(this))
        {
            return mln::se::rectangle(r->get_width(), r->get_height());
        }
        throw std::runtime_error("Not supported se_t type");
    }
}