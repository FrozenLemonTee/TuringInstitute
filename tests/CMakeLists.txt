# tests/CmakeLists.txt
include(FetchContent)

set(GTEST_GIT_REPO "git@github.com:google/googletest.git")
set(GTEST_HTTPS_REPO "https://github.com/google/googletest.git")
set(GTEST_REPO ${GTEST_GIT_REPO})

execute_process(
        COMMAND git ls-remote ${GTEST_REPO}
        RESULT_VARIABLE SSH_CLONE_RESULT
        OUTPUT_QUIET
        ERROR_QUIET
)

if(NOT SSH_CLONE_RESULT EQUAL 0)
    message(WARNING "SSH clone failed, falling back to HTTPS.")
    set(GTEST_REPO ${GTEST_HTTPS_REPO})
else()
    message(STATUS "SSH clone succeeded.")
endif()

FetchContent_Declare(
        GTest
        GIT_REPOSITORY ${GTEST_REPO}
        GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(GTest)

file(GLOB TESTS "test_*.cpp")

add_executable(tests ${TESTS})

target_link_libraries(tests GTest::gtest GTest::gmock GTest::gmock_main GTest::gtest_main)

target_link_libraries(tests TuringInstitute)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(NAME Tests COMMAND tests)