#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/dilation.hpp>
#include <mln/core/se/disc.hpp>

#include <mln/io/imread.hpp>
#include <mln/io/imsave.hpp>

#include <mln/core/concepts/structuring_element.hpp>
#include <stdexcept>

// This is in .hpp
class se_t
{
public:
    auto get_structuring_element();
private:
    virtual void polymorphic() = 0;
};

class my_disc : public se_t
{
public:
    my_disc(int rad) : radius(rad) {}
    int radius;
private:
    void polymorphic() override {}
};

// This is in .cpp
auto se_t::get_structuring_element()
{
    if (my_disc* d = dynamic_cast<my_disc*>(this))
    {
        return mln::se::disc(d->radius);
    }
    throw std::runtime_error("Not supported se_t type");
}

void dilation(mln::ndbuffer_image image, se_t& se)
{
    mln::image2d<uint8_t> input = *(image.template cast_to<uint8_t, 2>());
    mln::morpho::dilation(input, se.get_structuring_element());
}


int main(int argc, char** argv)
{
    mln::ndbuffer_image image(mln::sample_type_id::UINT8, 10, 10);
    my_disc mdisc(5);
    dilation(image, mdisc);


//   mln::ndbuffer_image image(mln::sample_type_id::UINT8, 10, 10);
//   mln::image2d<uint8_t> input = *(image.template cast_to<uint8_t, 2>());
//   mln::morpho::dilation(input, mln::se::disc(5));
}