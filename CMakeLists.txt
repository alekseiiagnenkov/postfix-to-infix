cmake_minimum_required(VERSION 3.17)
project(333)

set(CMAKE_CXX_STANDARD 17)

add_executable(333 main.c
        math.trans/math_trans.c
        math.trans/math_trans.h)