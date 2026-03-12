#include <format>
#include <iostream>
#include <chrono>

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

/*
 * Using the `chrono` library
 * Get the current system time using `system_clock::new()`
 * This was an older way of getting current time
 */
std::string getCurrentDateAndTime() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t( now );
    std::stringstream stringStream;
    // Y = year, m = month, d = day, X = hours and minutes
    stringStream << std::put_time( std::localtime( &in_time_t ), "%Y-%m-%d %X" );

    return stringStream.str();
}

/*
 * C++20 way of getting current time
 */
std::string getCurrentDateAndTime20() {
    auto const time = std::chrono::current_zone()->to_local( std::chrono::system_clock::now() );
    return std::format( "{:%Y-%m-%d %X}", time );
}

int main () {
    std::cout << __cplusplus << std::endl;
    /*
     * Get the middle of the year date
     */
    constexpr auto middle { std::chrono::June / std::chrono::last };
    std::cout << middle << std::endl;
    /*
     * Get the last Tuesday of the current year
     */
    constexpr auto ymwdl { std::chrono::year( 2026 ) / std::chrono::December / std::chrono::Tuesday[ std::chrono::last ] };
    std::cout << ymwdl.month() << ymwdl.weekday() << ymwdl.year() << std::endl;
    /*
     * Showing the current day and time from the two funtions below
     */
    std::cout
        << "Older: " << getCurrentDateAndTime()
        << "\nNewer: " << getCurrentDateAndTime20()
        << std::endl;
    /*
     * Gets the local timezone using `std::chrono::get_tzdb().current_zone()`
     * tzdb represents a copy of the IANA time zone database
     * `localTimezone` contains the following member functions
     * name(), get_info(), to_sys(), to_local()
     */
    const std::chrono::time_zone* localTimezone = std::chrono::get_tzdb().current_zone();
    std::cout << localTimezone->name() << std::endl;
    /*
     * Demonstrating using `Abbreviated Template Functions`
     * `max20` uses `Abbreviated Template Functions` using the `auto` keyword
     * `maxPrior` uses `template < typedef T, typedef U >`
     * The main advantage of `max20` is that you could also pass in two of the same type
     * such as two int's
     */
    int tValue = 19;
    double uValue = 19.19;

    std::cout 
        << "max20: " << max20( tValue, uValue )
        << "\nmaxPrior: " << maxPrior( tValue, uValue )
        << std::endl;

    return 0;
}