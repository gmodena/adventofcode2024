add_library(day19_part_one)
target_sources(day19_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day19_part_two)
target_sources(day19_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day19_input)
target_sources(day19_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
target_link_libraries(day19_part_one PRIVATE day19_input)
target_link_libraries(day19_part_two PRIVATE day19_input)

add_executable(day19 main.cc)
target_link_libraries(day19 day19_part_one day19_part_two day19_input)
