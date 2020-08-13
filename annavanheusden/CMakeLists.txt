
cmake_minimum_required(VERSION 3.15)

project(AnnaVanheusden)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnnaVanheusden.elf
        src/view/titlescreen/titlescreen.h
        src/Board_scene.cpp
        src/Board_scene.h
        src/main.cpp
        src/Titlescreen_scene.cpp
        src/Titlescreen_scene.h src/Player.cpp src/Player.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)


add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
