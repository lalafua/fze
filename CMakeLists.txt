cmake_minimum_required(VERSION 3.5)

project(
    fze
    LANGUAGES C CXX
    VERSION 25.03.26
    DESCRIPTION "For 408"
    )

add_compile_options(-Wall -Wextra -g)

# Set binary output path
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/)

# Set library output path
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/)

# Set header path
set(HEAD_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Set library name
set(CALCULATOR_LIB calculator)
set(SORT_LIB sort)

# Set exe name
set(FZE_NAME fze)

# Add sub directory
add_subdirectory(src/calculator)
add_subdirectory(src/sort)
add_subdirectory(src/fze)

# add_custom_target(run_main
#     COMMAND $<TARGET_FILE:main>
#     DEPENDS main
#     COMMENT "Running main..."
#     VERBATIM
#     )
