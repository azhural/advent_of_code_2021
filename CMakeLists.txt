cmake_minimum_required(VERSION 2.8)

project(aoc2021)

add_compile_options(-std=c++14)

include_directories(
  include
  )


file(GLOB TaskFiles src/tasks/*.cpp)
file(GLOB UtilFiles src/util/*.cpp)
add_library(${PROJECT_NAME}_util
  ${UtilFiles}
  )
add_library(${PROJECT_NAME}_tasks
  ${TaskFiles}
  )

add_executable(${PROJECT_NAME} src/main.cpp)

#target_link_libraries(${PROJECT_NAME}_util
#  )
#
target_link_libraries(${PROJECT_NAME}_tasks
  ${PROJECT_NAME}_util
  )
target_link_libraries(${PROJECT_NAME}
  ${PROJECT_NAME}_tasks
  )


