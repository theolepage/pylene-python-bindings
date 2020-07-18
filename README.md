# CPPA

Python bindings for [Pylene](https://gitlab.lrde.epita.fr/olena/pylene), a C++ image processing library.

## Build

1. `mkdir build && cd build`
2. `conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public`
3. `conan install .. --build missing -s compiler.cppstd=20`
4.  `cmake ..; make`

Alternatively, you can run our test suite by typing `make test`. By toggling `ALWAYS_SHOW_IMAGES` in `tests/test_example.py`, a comparison between output and expected test images will be shown.

## Usage

Start a Python3 interpreter in the folder of the generated `pylene.*.so`.

```python
from skimage import data
import pylene as pln

input1 = data.camera() # grayscale 8-bit image
input2 = data.retina() # rgb-8 image

out1 = pln.morpho.dilation(input1, pln.se.disc(4))
out2 = pln.morpho.dilation(input2, pln.se.rectangle(width=11, height=5))
```

## Authors

- Aymeric Fages
- Nicolas Blin
- Pierrick Made
- Theo Lepage
- Youssef Benkirane