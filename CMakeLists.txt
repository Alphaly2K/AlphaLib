cmake_minimum_required(VERSION 3.14)
project(AlphaLib)
set(SOURCES
    src/bignum.cpp
    src/text.cpp
)
add_library(AlphaLib SHARED ${SOURCES})
include_directories(include)
