cmake_minimum_required(VERSION 3.17)
project(ChunkList)

# To make Apple happy with catch2
if (APPLE)
    set(CMAKE_CXX_STANDARD 11)
endif()

# link with lld if available for speed
option(ENABLE_LLD "LLD" ON)
if (ENABLE_LLD)
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -fuse-ld=lld -Wl,--version ERROR_QUIET OUTPUT_VARIABLE LLD_VERSION)
    if(LLD_VERSION MATCHES "LLD")
        SET(LLD_AVAILABLE ON)
        MESSAGE(STATUS "lld linker available")
    endif()
endif()

# Precompile catch2 to speed up re-compiles
add_library(catch2_main STATIC unit_tests/catch_main.cpp)
target_include_directories(catch2_main PUBLIC unit_tests/)

# Driver executable
add_executable(ChunkList_Driver ChunkList_driver.cpp ChunkList.h)

# Test executables
add_executable(ChunkList_Test unit_tests/ChunkList_tests.cpp unit_tests/catch_main.cpp unit_tests/catch.hpp ChunkList.h)
add_executable(Constructor_Test unit_tests/constructor_tests.cpp unit_tests/catch_main.cpp unit_tests/catch.hpp ChunkList.h)
add_executable(Append_Remove_Test unit_tests/append_remove_tests.cpp unit_tests/catch_main.cpp unit_tests/catch.hpp ChunkList.h)
add_executable(Index_Test unit_tests/index_tests.cpp unit_tests/catch_main.cpp unit_tests/catch.hpp ChunkList.h)
add_executable(Iterator_Test unit_tests/iterator_tests.cpp unit_tests/catch_main.cpp unit_tests/catch.hpp ChunkList.h)
add_executable(Template_Test unit_tests/template_tests.cpp unit_tests/catch_main.cpp unit_tests/catch.hpp ChunkList.h)

# Use precompiled catch2 library for all of the executables to speed up recompile times
target_link_libraries(ChunkList_Test catch2_main)
#target_compile_definitions(ChunkList_Test PRIVATE CATCH_CONFIG_FAST_COMPILE CATCH_CONFIG_DISABLE_MATCHERS)
target_precompile_headers(ChunkList_Test PRIVATE unit_tests/catch.hpp)

target_link_libraries(Constructor_Test catch2_main)
#target_compile_definitions(Constructor_Test PRIVATE CATCH_CONFIG_FAST_COMPILE CATCH_CONFIG_DISABLE_MATCHERS)
target_precompile_headers(Constructor_Test PRIVATE unit_tests/catch.hpp)

target_link_libraries(Append_Remove_Test catch2_main)
#target_compile_definitions(Append_Remove_Test PRIVATE CATCH_CONFIG_FAST_COMPILE CATCH_CONFIG_DISABLE_MATCHERS)
target_precompile_headers(Append_Remove_Test PRIVATE unit_tests/catch.hpp)

target_link_libraries(Index_Test catch2_main)
#target_compile_definitions(Index_Test PRIVATE CATCH_CONFIG_FAST_COMPILE CATCH_CONFIG_DISABLE_MATCHERS)
target_precompile_headers(Index_Test PRIVATE unit_tests/catch.hpp)

target_link_libraries(Iterator_Test catch2_main)
#target_compile_definitions(Iterator_Test PRIVATE CATCH_CONFIG_DISABLE_MATCHERS)
target_precompile_headers(Iterator_Test PRIVATE unit_tests/catch.hpp)

target_link_libraries(Template_Test catch2_main)
#target_compile_definitions(Template_Test PRIVATE CATCH_CONFIG_FAST_COMPILE CATCH_CONFIG_DISABLE_MATCHERS)
target_precompile_headers(Template_Test PRIVATE unit_tests/catch.hpp)

# Fixes issue with catch and Apple
if (APPLE)
    set_property(TARGET ChunkList_Test PROPERTY CXX_STANDARD 11)
    set_property(TARGET Constructor_Test PROPERTY CXX_STANDARD 11)
    set_property(TARGET Append_Remove_Test PROPERTY CXX_STANDARD 11)
    set_property(TARGET Index_Test PROPERTY CXX_STANDARD 11)
    set_property(TARGET Iterator_Test PROPERTY CXX_STANDARD 11)
    set_property(TARGET Template_Test PROPERTY CXX_STANDARD 11)
endif()
