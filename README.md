# CPPA

Polymorphisme statique/dynamique pour Python.

## Usage

Start a Python3 interpreter in the folder of the generated `pylene.cpython-38-x86_64-linux-gnu.so`.

```python
import pylene as pln
pln.test()
```

## First install

### Build pybind11

1. `mkdir include; cd include`
2. `git clone https://github.com/pybind/pybind11.git`
3. `cd pybind11; mkdir build; cd build`
4. `sudo make install`

### Build this project

1. Create the build directory at the root of the repository: `mkdir build && cd build` (for releases) or `mkdir build_debug && cd build_debug`
2. `conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public`
3. `conan install .. --build missing -s compiler.cppstd=20`
4.  `cmake ..; make`

## Authors

- Aymeric Fages
- Nicolas Blin
- Pierrick Made
- Theo Lepage
- Youssef Benkirane