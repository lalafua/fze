cmake_minimum_required(VERSION 3.5)

project(fze_exe)
file(GLOB FZE_SRC ./*.c)

include_directories(${HEAD_PATH})

set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
link_directories(${LIB_PATH})

add_executable(${FZE_NAME} ${FZE_SRC})

target_link_libraries(
    ${FZE_NAME} 
    ${SORT_LIB}
    )

