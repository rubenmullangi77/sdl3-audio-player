cmake_minimum_required(VERSION 3.30)

project(audio-player C)

set(CMAKE_C_STANDARD 17)

set(SDL3_DIR "${CMAKE_SOURCE_DIR}/extern/SDL3/cmake")

find_package(SDL3 REQUIRED CONFIG)

add_executable(audio-player
    src/main.c
)

target_link_libraries(audio-player PRIVATE SDL3::SDL3)

if (WIN32)
    add_custom_command(
        TARGET audio-player POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3>
        $<TARGET_FILE_DIR:audio-player>
    )
endif()