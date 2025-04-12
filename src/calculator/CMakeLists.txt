cmake_minimum_required(VERSION 3.5)

project(calculator)

# Add source files
file(GLOB CALCULATOR_SRC ./*.c)

include_directories(${HEAD_PATH})

set(LIBRARY_OUTPUT_PATH ${LIB_PATH})

add_library(${CALCULATOR_LIB} SHARED ${CALCULATOR_SRC})