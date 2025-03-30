cmake_minimum_required(VERSION 3.5)

project(
    fze
    LANGUAGES C CXX
    VERSION 25.03.26
    DESCRIPTION "For 408"
    )

# Set C & CXX standard
set(CMAKE_CXX_STANDARD 17)

# Set binary output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

# Set library output path
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

# Headers path
include_directories(${PROJECT_SOURCE_DIR}/include/)

# Library path
include_directories(${PROJECT_SOURCE_DIR}/lib/)

# Find source files
file(GLOB MAIN_SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
file(GLOB MAIN_HEAD_LIST ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# Add files
add_executable(main ${MAIN_SRC_LIST})

add_library(fze SHARED ${MAIN_SRC_LIST})
#add_library(fze STATIC ${MAIN_SRC_LIST})

add_custom_target(run_main
    COMMAND $<TARGET_FILE:main>
    DEPENDS main
    COMMENT "Running main..."
    VERBATIM
    )
