cmake_minimum_required(VERSION 3.14)
project(Ex5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ex5 Demo.cpp
        range.cpp range.hpp
        chain.cpp chain.hpp
        zip.cpp zip.hpp
        product.cpp product.hpp
        powerset.cpp powerset.hpp)