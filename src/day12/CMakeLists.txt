add_library(day12_part_one)
target_sources(day12_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day12_part_two)
target_sources(day12_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day12_input)
target_sources(day12_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day12_part_one PRIVATE day12_input)
target_link_libraries(day12_part_two PRIVATE day12_input)

add_executable(day12 main.cc)
target_link_libraries(day12 day12_part_one day12_part_two day12_input)
