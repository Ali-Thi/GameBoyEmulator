include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(googletest)

add_executable(test cpu/registers/registerA.cc
        cpu/registers/registerF.cc
        cpu/registers/registerB.cc
        cpu/registers/registerC.cc
        cpu/registers/registerD.cc
        cpu/registers/registerE.cc
        cpu/registers/registerH.cc
        cpu/registers/registerL.cc
        cpu/registers/registerAF.cc
        cpu/registers/registerBC.cc
        cpu/registers/registerDE.cc
        cpu/registers/registerHL.cc
        cpu/add.cc
        cpu/addhl.cc
        cpu/adc.cc
        cpu/sub.cc
        cpu/subc.cc
        cpu/and.cc
)
target_compile_options(test PRIVATE -Wall -Wextra -Werror -pedantic -Wold-style-cast)
target_link_libraries(test gtest gtest_main cpu)