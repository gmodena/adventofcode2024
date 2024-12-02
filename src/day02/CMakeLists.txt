add_library(day02_part_one)
target_sources(day02_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day02_part_two)
target_sources(day02_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day02_input)
target_sources(day02_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day02_part_two PRIVATE day02_part_one)

add_executable(day02 main.cc)
target_link_libraries(day02 day02_part_one day02_part_two day02_input)
