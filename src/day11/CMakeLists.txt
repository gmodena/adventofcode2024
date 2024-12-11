add_library(day11_part_one)
target_sources(day11_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day11_part_two)
target_sources(day11_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day11_input)
target_sources(day11_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day11_part_one PRIVATE day11_input)
target_link_libraries(day11_part_two PRIVATE day11_input)

add_executable(day11 main.cc)
target_link_libraries(day11 day11_part_one day11_part_two day11_input)
