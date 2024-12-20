add_library(day20_part_one)
target_sources(day20_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day20_part_two)
target_sources(day20_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)
target_link_libraries(day20_part_two PRIVATE day20_part_one)


add_library(day20_input)
target_sources(day20_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day20_part_one PRIVATE day20_input)
target_link_libraries(day20_part_two PRIVATE day20_input)

add_executable(day20 main.cc)
target_link_libraries(day20 day20_part_one day20_part_two day20_input)
