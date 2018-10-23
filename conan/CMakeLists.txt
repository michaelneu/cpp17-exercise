project(HashExercise)
cmake_minimum_required(VERSION 2.8.12)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(hash hash.cpp)
target_link_libraries(hash ${CONAN_LIBS})
