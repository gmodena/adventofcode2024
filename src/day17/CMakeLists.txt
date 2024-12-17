add_library(day17_part_one)
target_sources(day17_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day17_part_two)
target_sources(day17_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day17_input)
target_sources(day17_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day17_part_one PRIVATE day17_input)
target_link_libraries(day17_part_two PRIVATE day17_input)

add_executable(day17 main.cc)
target_link_libraries(day17 day17_part_one day17_part_two day17_input)
