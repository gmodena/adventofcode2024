add_library(day14_part_one)
target_sources(day14_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day14_part_two)
target_sources(day14_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day14_input)
target_sources(day14_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day14_part_one PRIVATE day14_input)
target_link_libraries(day14_part_two PRIVATE day14_input)

add_executable(day14 main.cc)
target_link_libraries(day14 day14_part_one day14_part_two day14_input)
