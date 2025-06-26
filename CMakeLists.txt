cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramming VERSION 0.1.0 LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)
find_package(Matplot++ CONFIG REQUIRED)

add_library(Utils Utils/Performance.cpp)
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Utils)
target_link_libraries(Utils PUBLIC fmt::fmt Matplot++::cimg Matplot++::matplot)

file(GLOB_RECURSE SCRIPT_FILES "Code/*.cpp")

foreach(script_file ${SCRIPT_FILES})
    file(RELATIVE_PATH rel_path ${CMAKE_CURRENT_SOURCE_DIR}/Code ${script_file})
    string(REPLACE "/" "-" script_name ${rel_path})
    string(REPLACE ".cpp" "" script_name ${script_name})

    add_executable(${script_name} ${script_file})
    target_link_libraries(${script_name} PRIVATE Utils)
endforeach()

add_executable(Performance Utils/Performance)
target_link_libraries(Performance PRIVATE fmt::fmt Matplot++::cimg  Matplot++::matplot)