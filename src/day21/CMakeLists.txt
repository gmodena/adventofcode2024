add_library(day21_part_one)
target_sources(day21_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day21_part_two)
target_sources(day21_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day21_input)
target_sources(day21_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day21_part_one PRIVATE day21_input)
target_link_libraries(day21_part_two PRIVATE day21_input)

add_executable(day21 main.cc)
target_link_libraries(day21 day21_part_one day21_part_two day21_input)
