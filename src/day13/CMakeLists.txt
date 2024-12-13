add_library(day13_part_one)
target_sources(day13_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day13_part_two)
target_sources(day13_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day13_input)
target_sources(day13_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day13_part_one PRIVATE day13_input)
target_link_libraries(day13_part_two PRIVATE day13_input)

add_executable(day13 main.cc)
target_link_libraries(day13 day13_part_one day13_part_two day13_input)
