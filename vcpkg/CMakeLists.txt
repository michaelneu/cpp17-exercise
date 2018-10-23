project(HashExercise)
cmake_minimum_required(VERSION 3.0)

add_definitions("-std=c++17")

find_package(OpenSSL REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(hash hash.cpp)
target_link_libraries(hash PUBLIC OpenSSL::Crypto fmt::fmt)
