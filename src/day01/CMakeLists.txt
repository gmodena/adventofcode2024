add_library(day01_part_one)
target_sources(day01_part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(day01_part_two)
target_sources(day01_part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_library(day01_input)
target_sources(day01_input PUBLIC FILE_SET CXX_MODULES FILES input.cc)


add_executable(day01 main.cc)
target_link_libraries(day01 day01_part_one day01_part_two day01_input)
