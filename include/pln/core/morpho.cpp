#include "morpho.hpp"

#include <mln/morpho/dilation.hpp>
#include <mln/morpho/closing.hpp>
#include <mln/morpho/opening.hpp>
#include <mln/morpho/erosion.hpp>
#include <mln/core/image/ndimage.hpp>

#include "se.hpp"

namespace pln {
    void dilation(mln::ndbuffer_image image, se_t& se)
    {
        mln::morpho::dilation(*(image.template cast_to<uint8_t, image.pdim()>()),
                                                se.get_structuring_element());
    }

    void erosion(mln::ndbuffer_image image, se_t& se)
    {
        mln::morpho::erosion(*(image.template cast_to<uint8_t, image.pdim()>()),
                                                se.get_structuring_element());
    }

    void opening(mln::ndbuffer_image image, se_t& se)
    {
        mln::morpho::opening(*(image.template cast_to<uint8_t, image.pdim()>()),
                                                se.get_structuring_element());
    }

    void closing(mln::ndbuffer_image image, se_t& se)
    {
        mln::morpho::closing(*(image.template cast_to<uint8_t, image.pdim()>()),
                                                se.get_structuring_element());
    }
}