cmake_minimum_required(VERSION 3.12)
project(BoundedQueueExample)

set(CMAKE_CXX_STANDARD 14)

# Locate GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Enable code coverage
set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_EXE_LINKER_FLAGS "--coverage")

# Add the main.cpp and bounded_queue.h to the project
add_executable(BoundedQueueExample main.cpp bounded_queue.h)

target_link_libraries(BoundedQueueExample ${GTEST_LIBRARIES} Threads::Threads)

# Add a custom target to run the main executable
add_custom_target(run_main
    COMMAND BoundedQueueExample
    DEPENDS BoundedQueueExample
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add the test_bounded_queue.cpp file to the project
add_executable(TestBoundedQueue test_bounded_queue.cpp bounded_queue.h)

# Link the TestBoundedQueue executable with GoogleTest
target_link_libraries(TestBoundedQueue ${GTEST_LIBRARIES} Threads::Threads)
target_link_libraries(TestBoundedQueue gtest gtest_main)
target_include_directories(TestBoundedQueue PRIVATE include)

# Add a custom target to run the tests
add_custom_target(run_tests
    COMMAND TestBoundedQueue
    DEPENDS TestBoundedQueue
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add a custom target for code coverage
add_custom_target(coverage
    COMMAND lcov --capture --directory . --output-file coverage.info
    COMMAND lcov --remove coverage.info '/usr/*' '${PROJECT_SOURCE_DIR}/gtest/*' --output-file coverage.info
    COMMAND lcov --list coverage.info
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating code coverage report"
)
