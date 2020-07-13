#pragma once

#include <mln/core/image/ndimage.hpp>

#include "se.hpp"

namespace pln {
    mln::ndbuffer_image dilation(mln::ndbuffer_image image, se_t&& se);
    void erosion(mln::ndbuffer_image image, se_t&& se);
    void opening(mln::ndbuffer_image image, se_t&& se);
    void closing(mln::ndbuffer_image image, se_t&& se);
}