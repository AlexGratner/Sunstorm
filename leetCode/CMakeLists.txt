include_directories ("${PROJECT_SOURCE_DIR}/util")
include_directories ("${PROJECT_SOURCE_DIR}/catch2")

find_package(Catch2 REQUIRED)

add_executable (1-TwoSum 1-TwoSum.cpp)

target_link_libraries (1-TwoSum util)
target_link_libraries (1-TwoSum testsmain)

include(CTest)
include(Catch)
catch_discover_tests(1-TwoSum)

