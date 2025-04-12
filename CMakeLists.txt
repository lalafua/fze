cmake_minimum_required(VERSION 3.5)

project(
    fze
    LANGUAGES C CXX
    VERSION 25.03.26
    DESCRIPTION "For 408"
    )

add_compile_options(-Wall -Wextra -g)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set path
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/)
set(HEAD_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Add sub directory
add_subdirectory(src/calculator)
add_subdirectory(src/sort)

# Add main directory
add_subdirectory(src/fze_exe)


add_custom_target(run_tests
    COMMAND ${EXEC_PATH}/fze_exe
    DEPENDS fze_exe
    COMMENT "Running tests..."
    VERBATIM
    )
