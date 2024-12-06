add_library(day06_part_one)
target_sources(day06_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day06_part_two)
target_sources(day06_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day06_input)
target_sources(day06_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day06_part_one PRIVATE day06_input)
target_link_libraries(day06_part_two PRIVATE day06_input)

add_executable(day06 main.cc)
target_link_libraries(day06 day06_part_one day06_part_two day06_input)
