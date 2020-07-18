#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/dilation.hpp>
#include <mln/core/se/disc.hpp>

#include <mln/io/imread.hpp>
#include <mln/io/imsave.hpp>


int main(int argc, char** argv)
{
  mln::image2d<uint8_t> input;

  mln::io::imread(argv[1], input);
  auto output = mln::morpho::dilation(input, mln::se::disc(5));
  mln::io::imsave(output, argv[2]);
}