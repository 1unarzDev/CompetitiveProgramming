cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramming VERSION 0.1.0 LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)
find_package(Matplot++ CONFIG REQUIRED)

add_executable(Performance Utils/Performance.cpp)

target_link_libraries(Performance PRIVATE fmt::fmt)
target_link_libraries(Performance PRIVATE Matplot++::cimg  Matplot++::matplot)