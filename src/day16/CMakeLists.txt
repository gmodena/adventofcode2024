add_library(day16_part_one)
target_sources(day16_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day16_part_two)
target_sources(day16_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)
target_link_libraries(day16_part_two PRIVATE day16_part_one)

add_library(day16_input)
target_sources(day16_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day16_part_one PRIVATE day16_input)
target_link_libraries(day16_part_two PRIVATE day16_input)

add_executable(day16 main.cc)
target_link_libraries(day16 day16_part_one day16_part_two day16_input)
