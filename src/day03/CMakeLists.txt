add_library(day03_part_one)
target_sources(day03_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day03_part_two)
target_sources(day03_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day03_input)
target_sources(day03_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day03_part_two PRIVATE day03_part_one)

add_executable(day03 main.cc)
target_link_libraries(day03 day03_part_one day03_part_two day03_input)
