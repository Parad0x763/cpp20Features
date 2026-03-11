#include <iostream>

/* 
 * The following `max` function is intended to determine the max value between to different types
 * Such as an `int` and a `double`
 */
/* C++20 Added Abbreviated function templates */
auto max20( auto x, auto y ) {
    return ( x < y ) ? y : x;
}

/* Prior to C++20 you this function could look like the following */
template < typename T, typename U >
auto maxPrior( T x, U y ) {
    return ( x < y ) ? y : x;
}

int main () {
    std::cout << __cplusplus << std::endl;

    int tValue = 19;
    double uValue = 19.19;

    std::cout 
        << "max20: " << max20( tValue, uValue )
        << "\nmaxPrior: " << maxPrior( tValue, uValue )
        << std::endl;

    return 0;
}