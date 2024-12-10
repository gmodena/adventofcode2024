add_library(day10_part_one)
target_sources(day10_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day10_part_two)
target_sources(day10_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)
target_link_libraries(day10_part_two PRIVATE day10_part_one)

add_library(day10_input)
target_sources(day10_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day10_part_one PRIVATE day10_input)
target_link_libraries(day10_part_two PRIVATE day10_input)

add_executable(day10 main.cc)
target_link_libraries(day10 day10_part_one day10_part_two day10_input)
