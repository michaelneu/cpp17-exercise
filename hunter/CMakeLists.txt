cmake_minimum_required(VERSION 3.2)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.34.tar.gz"
    SHA1 "70287b1ffa810ee4e952052a9adff9b4856d0d54"
)

project(HashExercise)

add_definitions("-std=c++17")

hunter_add_package(OpenSSL)
find_package(OpenSSL REQUIRED)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

add_executable(hash hash.cpp)
target_link_libraries(hash PUBLIC OpenSSL::Crypto fmt::fmt)
