cmake_minimum_required(VERSION 3.2)
project(s21_smart_calc)

# set(CMAKE_C_COMPILER "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc")
# set(CMAKE_CXX_COMPILER "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++")

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# -Wall -Werror -Wextra -Wpedantic --coverage 
# -fsanitize=leak -fsanitize=address
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON) 

# find_package(Doxygen)
# if (DOXYGEN_FOUND)
#   if (NOT MYLIB_DOXYGEN_LANGUAGE)
#     set(MYLIB_DOXYGEN_LANGUAGE Russian)
#   endif()
#     # Настройка Doxygen
#     set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
#     set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile)
#     configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#     add_custom_target(documentation ALL
#         COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#         COMMENT "Generating API documentation with Doxygen"
#         VERBATIM)
# else (DOXYGEN_FOUND)
#     message(WARNING "Doxygen not found. Documentation won't be generated.")
# endif (DOXYGEN_FOUND)

include(FetchContent)
# download gtest
FetchContent_Declare(
  googletest
  #URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(src/calculator)
add_executable(
  tests
  src/tests/calculator_unittest.cc
  src/tests/tokenizer_unittest.cc
  src/tests/credit_calculator_unittest.cc
)

target_link_libraries(
    tests
    credit_calculator
    calculator
    GTest::gmock
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)