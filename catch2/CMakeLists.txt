find_package(Catch2 REQUIRED)

add_library(testsmain tests-main.cpp)
target_link_libraries (testsmain Catch2::Catch2)

