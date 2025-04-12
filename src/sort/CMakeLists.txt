cmake_minimum_required(VERSION 3.5)

project(sort)
file(GLOB SORT_SRC ./*.c)

include_directories(${HEAD_PATH})

set(LIBRARY_OUTPUT_DIRECTORY ${LIB_PATH})

# add_library(${SORT_LIB} SHARED ${SORT_SRC})