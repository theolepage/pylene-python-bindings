#include "morpho.hpp"

#include <mln/morpho/dilation.hpp>
#include <mln/morpho/closing.hpp>
#include <mln/morpho/opening.hpp>
#include <mln/morpho/erosion.hpp>
#include <mln/core/image/ndimage.hpp>

#include <mln/core/se/disc.hpp>
#include <mln/core/se/mask2d.hpp>

#include "se.hpp"

#include <iostream>

namespace pln {
    mln::ndbuffer_image dilation(mln::ndbuffer_image image, se_t&& se)
    {
        return mln::morpho::dilation(*(image.cast_to<uint8_t, 2>()), mln::se::disc(5));
    }

    void erosion(mln::ndbuffer_image image, se_t&& se)
    {
        // mln::morpho::erosion(*(image.template cast_to<uint8_t, image.pdim()>()),
                                                // se.get_structuring_element());
    }

    void opening(mln::ndbuffer_image image, se_t&& se)
    {
        // mln::morpho::opening(*(image.template cast_to<uint8_t, image.pdim()>()),
                                                // se.get_structuring_element());
    }

    void closing(mln::ndbuffer_image image, se_t&& se)
    {
        // mln::morpho::closing(*(image.template cast_to<uint8_t, image.pdim()>()),
                                                // se.get_structuring_element());
    }
}