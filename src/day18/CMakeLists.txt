add_library(day18_part_one)
target_sources(day18_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day18_part_two)
target_sources(day18_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)
target_link_libraries(day18_part_two PRIVATE day18_part_one)

add_library(day18_input)
target_sources(day18_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day18_part_one PRIVATE day18_input)
target_link_libraries(day18_part_two PRIVATE day18_input)

add_executable(day18 main.cc)
target_link_libraries(day18 day18_part_one day18_part_two day18_input)
