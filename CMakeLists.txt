cmake_minimum_required(VERSION 3.0)
project(ChanSTL)

include_directories(./)
aux_source_directory(./tests/ SRC)
add_executable(allocator_test tests/allocator_test.cc)

enable_testing()
