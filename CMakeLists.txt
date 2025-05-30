cmake_minimum_required(VERSION 3.14)
project(glpaper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_executable(glpaper
  src/main.cpp
  src/wallpaper.cpp
)

target_include_directories(glpaper PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(glpaper PRIVATE
  sfml-graphics
  sfml-window
  sfml-system
  fmt::fmt
  spdlog::spdlog
)
