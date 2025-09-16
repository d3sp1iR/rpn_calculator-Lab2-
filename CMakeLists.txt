cmake_minimum_required(VERSION 3.14)
project(RPN_Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основное приложение
add_executable(rpn_calculator src/main.cpp src/rpn.cpp include/rpn.h)

target_include_directories(rpn_calculator PUBLIC include)

# ЗАКОММЕНТИРОВАТЬ или УДАЛИТЬ все что связано с тестами
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9fd718599d30c5a443a4b0b.zip
# )
# 
# FetchContent_MakeAvailable(googletest)
# 
# add_subdirectory(tests)