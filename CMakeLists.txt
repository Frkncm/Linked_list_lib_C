cmake_minimum_required(VERSION 3.14)

project(linked_list_prj)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(gtest_gmock)
include_directories(linked_list_lib)
include_directories(linked_list_lib/inc)
include_directories(linked_list_lib/src)
include_directories(tests)

add_executable(linked_list_prj
    main.cpp
    linked_list_lib/inc/linked_list.h
    linked_list_lib/src/linked_list.c
    tests/test1.cpp
    tests/test2.cpp
    gtest_gmock/gmock/gmock.h
  	gtest_gmock/gtest/gtest.h
  	gtest_gmock/gmock-gtest-all.cc
)

set_target_properties(linked_list_prj PROPERTIES LINK_LIBRARIES -pthread)
