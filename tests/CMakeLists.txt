# tests/CmakeLists.txt
include(FetchContent)

set(MIRROR_REPO "https://gitee.com/mirrors/googletest.git")
set(GTEST_GIT_REPO "git@github.com:google/googletest.git")
set(GTEST_HTTPS_REPO "https://github.com/google/googletest.git")

set(REPO_PRIORITY_LIST
        ${GTEST_GIT_REPO}
        ${GTEST_HTTPS_REPO}
        ${MIRROR_REPO}
)

foreach(repo IN LISTS REPO_PRIORITY_LIST)
    execute_process(
            COMMAND git ls-remote ${repo}
            RESULT_VARIABLE result
            OUTPUT_QUIET
            ERROR_QUIET
            TIMEOUT 10
    )
    if(result EQUAL 0)
        set(GTEST_REPO ${repo})
        message(STATUS "Using repository: ${repo}")
        break()
    else()
        message(WARNING "Repository unavailable: ${repo}")
    endif()
endforeach()

if(NOT GTEST_REPO)
    message(FATAL_ERROR "All repositories are unavailable!")
endif()

FetchContent_Declare(
        GTest
        GIT_REPOSITORY ${GTEST_REPO}
        GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(GTest)

file(GLOB TESTS "test_*.cpp")

add_executable(tests ${TESTS})

target_link_libraries(tests GTest::gtest GTest::gmock GTest::gmock_main GTest::gtest_main)

target_link_libraries(tests TuringInstitute)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(NAME Tests COMMAND tests)