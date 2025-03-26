cmake_minimum_required(VERSION 3.5)

project(
    fze
    LANGUAGES C CXX
    VERSION 25.03.26
    DESCRIPTION "For 408"
    )

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SRC_LIST src/main.c)


add_executable(main ${SRC_LIST})

add_custom_target(run_main
    COMMAND $<TARGET_FILE:main>
    DEPENDS main
    COMMENT "Running main..."
    VERBATIM
    )
