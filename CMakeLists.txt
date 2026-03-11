cmake_minimum_required( VERSION 3.10 )
project( cpp20features )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g" )
set( CMAKE_CXX_STANDARD 20 )

set(
    sources
    main.cpp
)

list( FILTER SOURCES EXCLUDE REGEX "CMakeFiles.*\\.cpp$" )

add_executable( main ${sources} )