# CPPA

Python bindings for Pylene, a C++ image processing library.

## Usage

Start a Python3 interpreter in the folder of the generated `pylene.cpython-38-x86_64-linux-gnu.so`.

```python
from skimage import data
import pylene as pln

input1 = data.camera() # grayscale 8-bit image
input2 = data.retina() # rgb-8 image

out1 = pln.morpho.dilation(input1, pln.se.disc(4))
out2 = pln.morpho.dilation(input2, pln.se.rectangle(width=11, height=5))
```

## Build

1. Create the build directory at the root of the repository: `mkdir build && cd build` (for releases) or `mkdir build_debug && cd build_debug`
2. `conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public`
3. `conan install .. --build missing -s compiler.cppstd=20`
4.  `cmake ..; make`

## To-Do

- [ ] Create simple python test suite
- [ ] Clean code, error handling, refactor, add documentation
- [ ] Write report

## Resources

- [https://gitlab.lrde.epita.fr/olena/pylene](https://gitlab.lrde.epita.fr/olena/pylene)
- [https://pybind11.readthedocs.io/en/master/basics.html](https://pybind11.readthedocs.io/en/master/basics.html)

## Authors

- Aymeric Fages
- Nicolas Blin
- Pierrick Made
- Theo Lepage
- Youssef Benkirane