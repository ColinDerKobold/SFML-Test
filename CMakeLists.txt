cmake_minimum_required(VERSION 3.28)

project(SFML_Test)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "C:/Programme/SFML-3.1.0/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(SFML_Test main.cpp)

target_link_libraries(SFML_Test PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

add_custom_command(TARGET SFML_Test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "C:/Programme/SFML-3.1.0/bin"
        $<TARGET_FILE_DIR:SFML_Test>
)