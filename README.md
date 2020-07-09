# Install

1. Create your build directory (Release or Debug)

```
mkdir build && cd build # Release
```

or

```
mkdir build_debug && cd build_debug
```

2. Install project dependancies with the [conan](https://docs.conan.io/en/latest/introduction.html) package manager.

add remote to pylene

```
conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public
```

```
conan profile update settings.compiler.libcxx=libstdc++11 default
conan install .. --build missing
```

(using a C++ package manager avoid version incompatibities)

    4. Build the project with cmake

```
cmake ..
```
