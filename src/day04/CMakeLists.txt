add_library(day04_part_one)
target_sources(day04_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day04_part_two)
target_sources(day04_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day04_input)
target_sources(day04_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day04_part_two PRIVATE day04_part_one)

add_executable(day04 main.cc)
target_link_libraries(day04 day04_part_one day04_part_two day04_input)
