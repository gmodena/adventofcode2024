add_library(day23_part_one)
target_sources(day23_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day23_part_two)
target_sources(day23_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day23_input)
target_sources(day23_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day23_part_one PRIVATE day23_input)
target_link_libraries(day23_part_two PRIVATE day23_input)

add_executable(day23 main.cc)
target_link_libraries(day23 day23_part_one day23_part_two day23_input)
