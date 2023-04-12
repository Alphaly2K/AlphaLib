cmake_minimum_required(VERSION 3.14)
project(AlphaLib)
set(SOURCES
    src/bignum.cpp
)
add_library(AlphaLib STATIC ${SOURCES})
include_directories(include)
