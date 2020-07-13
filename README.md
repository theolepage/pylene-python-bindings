# CPPA

Polymorphisme statique/dynamique pour Python.

## Usage

Start a Python3 interpreter in the folder of the generated `pylene.cpython-38-x86_64-linux-gnu.so`.

```python
import numpy as np
import pylene as pln

arr = np.array([[1, 0], [0, 1]])

pln.morpho.dilation(arr)
```

## Build

1. Create the build directory at the root of the repository: `mkdir build && cd build` (for releases) or `mkdir build_debug && cd build_debug`
2. `conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public`
3. `conan install .. --build missing -s compiler.cppstd=20`
4.  `cmake ..; make`

## To-Do

- [ ] Bug: output not changed
- [ ] Bug: determine good dimensions for convert
- [ ] Template morpho by type
- [ ] Se_t
- [ ] Hard code image2d?

- [ ] Clean code, error handling, refactor, add documentation
- [ ] Create simple python test suite / make GTest work
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