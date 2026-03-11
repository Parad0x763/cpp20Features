# Exploring C++ 20

## vcpkg

- `vcpgk new --application`

## cmake

- `cmake -B build/ -S . -GNinja -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake`
- To make sure that `cmake` builds for C++20, add the following to `CMakeLists.txt`
  - `set( CMAKE_CXX_STANDARD 20 )`
  - Also note that you can print out the C++ verion using the following `__cplusplus` macro:
    - `std::cout << __cplusplus << std::endl;`
      - prints: `202002` on my system