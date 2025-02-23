# tests/CmakeLists.txt
include(FetchContent)

FetchContent_Declare(
        GTest
        GIT_REPOSITORY git@github.com:/google/googletest
        GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(GTest)

file(GLOB TESTS "test_*.cpp")

add_executable(tests ${TESTS})

target_link_libraries(tests GTest::gtest GTest::gmock GTest::gmock_main GTest::gtest_main)

target_link_libraries(tests TuringInstitute)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(NAME Tests COMMAND tests)