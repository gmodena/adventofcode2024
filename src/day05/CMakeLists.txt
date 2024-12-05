add_library(day05_part_one)
target_sources(day05_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day05_part_two)
target_sources(day05_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day05_input)
target_sources(day05_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day05_part_two PRIVATE day05_part_one)

add_executable(day05 main.cc)
target_link_libraries(day05 day05_part_one day05_part_two day05_input)
