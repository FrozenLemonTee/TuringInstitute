include(FetchContent)

set(MIRROR_REPO "https://gitee.com/mirrors/googletest.git")
set(GTEST_GIT_REPO "git@github.com:google/googletest.git")
set(GTEST_HTTPS_REPO "https://github.com/google/googletest.git")

set(REPO_PRIORITY_LIST
        ${GTEST_GIT_REPO}
        ${GTEST_HTTPS_REPO}
        ${MIRROR_REPO}
)

set(GTEST_REPO "")
set(GTEST_CLONE_DIR "${CMAKE_BINARY_DIR}/googletest-src")

foreach(repo IN LISTS REPO_PRIORITY_LIST)
    message(STATUS "Trying repository: ${repo}")
    execute_process(
            COMMAND git ls-remote ${repo}
            RESULT_VARIABLE result
            OUTPUT_QUIET
            ERROR_QUIET
            TIMEOUT 10
    )
    if(result EQUAL 0)
        execute_process(
                COMMAND git clone --depth=1 --branch release-1.11.0 ${repo} ${GTEST_CLONE_DIR}
                RESULT_VARIABLE clone_result
                OUTPUT_QUIET
                ERROR_QUIET
                TIMEOUT 30
        )
        if(clone_result EQUAL 0)
            set(GTEST_REPO ${repo})
            message(STATUS "Successfully cloned from: ${repo}")
            break()
        else()
            message(WARNING "Failed to clone from: ${repo}, trying next repository...")
        endif()
    else()
        message(WARNING "Repository unavailable: ${repo}")
    endif()
endforeach()

if(NOT GTEST_REPO)
    message(FATAL_ERROR "All repositories are unavailable!")
endif()

FetchContent_Declare(
        GTest
        SOURCE_DIR ${GTEST_CLONE_DIR}
)

FetchContent_MakeAvailable(GTest)

file(GLOB TESTS "test_*.cpp")

add_executable(tests ${TESTS})

target_link_libraries(tests GTest::gtest GTest::gmock GTest::gmock_main GTest::gtest_main)

target_link_libraries(tests TuringInstitute)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(NAME Tests COMMAND tests)
