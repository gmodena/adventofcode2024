add_library(day07_part_one)
target_sources(day07_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day07_part_two)
target_sources(day07_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day07_input)
target_sources(day07_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day07_part_one PRIVATE day07_input)
target_link_libraries(day07_part_two PRIVATE day07_input)

add_executable(day07 main.cc)
target_link_libraries(day07 day07_part_one day07_part_two day07_input)
