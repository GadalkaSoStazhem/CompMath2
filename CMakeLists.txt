cmake_minimum_required(VERSION 3.23)
project(CompMath2)

set(CMAKE_CXX_STANDARD 14)

add_executable(CompMath2 main.cpp my_locale.h equations.h io.h single.h systems.h linear.h)
