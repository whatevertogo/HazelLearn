cmake_minimum_required(VERSION 3.30)
project(HazelLearn)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(Sandbox)
add_subdirectory(Hazel)

target_link_libraries(Sandbox Hazel)
