cmake_minimum_required(VERSION 3.26)
project(awesome-cpp-modules CXX)

set(CMAKE_CXX_STANDARD 20)

if(CMAKE_VERSION VERSION_LESS "3.27.0")
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
else()
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")
endif()

# Check and set compiler dependant settings
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.34)
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
  
    # Project files
    add_executable(hello main.cc)
    target_sources(hello
      PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        foo.cc
    )

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"  AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 13.0)
    set(CMAKE_CXX_FLAGS "-fmodules-ts")
    set(CMAKE_CXX_EXTENSIONS ON)

    # Project files
    add_executable(hello foo.cc main.cc) # order matters
    target_link_libraries(hello)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 17)
    find_program(CLANG_TIDY NAMES clang-tidy REQUIRED)
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "clang")
    set(CMAKE_EXE_LINKER_FLAGS -lstdc++)

    # Project files
    add_library(foo)
    target_sources(foo PUBLIC FILE_SET CXX_MODULES FILES
        foo.cc
    )
    add_executable(hello main.cc)
    target_link_libraries(hello foo)
    
else()
    message(FATAL_ERROR "Newer c++ compiler required")
endif()
