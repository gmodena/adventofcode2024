add_library(day08_part_one)
target_sources(day08_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day08_part_two)
target_sources(day08_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day08_input)
target_sources(day08_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day08_part_one PRIVATE day08_input)
target_link_libraries(day08_part_two PRIVATE day08_input)

add_executable(day08 main.cc)
target_link_libraries(day08 day08_part_one day08_part_two day08_input)
