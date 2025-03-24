add_library(cpu SHARED cpu.cc)

target_include_directories(cpu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(cpu PRIVATE -Wall -Wextra -Werror -pedantic -Wold-style-cast)