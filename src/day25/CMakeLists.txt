add_library(day25_part_one)
target_sources(day25_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day25_part_two)
target_sources(day25_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day25_input)
target_sources(day25_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day25_part_one PRIVATE day25_input)
target_link_libraries(day25_part_two PRIVATE day25_input)

add_executable(day25 main.cc)
target_link_libraries(day25 day25_part_one day25_part_two day25_input)
