# Main CmakeLists.txt

cmake_minimum_required(VERSION 3.30)
project(TuringInstitute)

set(CMAKE_CXX_STANDARD 20)
include_directories(${CMAKE_SOURCE_DIR})

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/lib
)
link_directories(${PROJECT_SOURCE_DIR}/lib)
file(GLOB LIB_SRC
        "${PROJECT_SOURCE_DIR}/lib/*.cpp"
)
add_library(TuringInstitute STATIC ${LIB_SRC})

# Tests
add_subdirectory(tests)