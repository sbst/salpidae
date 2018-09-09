cmake_minimum_required(VERSION 2.8.11)
project(salpidae)

set(CXXFLAGS -Wall -std=c++14)

find_package(Boost 1.36.0)

file(GLOB Sources *.cpp)
add_executable(${PROJECT_NAME} ${Sources})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
link_directories(${PROJECT_SOURCE_DIR})
target_compile_options(${PROJECT_NAME} PUBLIC ${CXXFLAGS})

