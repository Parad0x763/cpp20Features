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

## C++20

- [CPPReference](https://en.cppreference.com/index.html)
- [Intro-to-C++20](https://www.learncpp.com/cpp-tutorial/introduction-to-c20/)

### Abbreviated Function Templates

- Allow for shorthand generic type definition in functions by using `auto`
- Provides more robust use cases
  - For example with the previous way
```
  template< typedef T, typedef U >
  T max( T x, U y ) {
    return ( x < y ) ? y : x;
  }
```
  - The `max` function would error when passing `x` as an `int` and `y` as a `double` because the compiler does not handle type conversion automatically with templates
- Using the `Abbreviated Function Templates` approach the previous issue is no longer a problem
```
  auto max( auto x, auto y ) {
    return ( x < y ) ? y : x;
  }
```

### Chrono Library ( originally introduced in C++11 )

- [Chrono](https://en.cppreference.com/w/cpp/chrono.html)
  - This site shows which standard introduced which feature / class / struct

#### Main Types Added

- [calendar](https://en.cppreference.com/w/cpp/chrono.html#Calendar) and [time zone](https://en.cppreference.com/w/cpp/chrono.html#Time_zone) where added

#### Calendar

- Adds many classes for getting expected calendar dates / functionality
- 