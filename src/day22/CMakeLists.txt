add_library(day22_part_one)
target_sources(day22_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day22_part_two)
target_sources(day22_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)
target_link_libraries(day22_part_two PRIVATE day22_part_one)

add_library(day22_input)
target_sources(day22_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day22_part_one PRIVATE day22_input)
target_link_libraries(day22_part_two PRIVATE day22_input)

add_executable(day22 main.cc)
target_link_libraries(day22 day22_part_one day22_part_two day22_input)
