cmake_minimum_required(VERSION 3.28)

project(Go_SFML LANGUAGES CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main)

target_sources(main
    PRIVATE
        src/main.cc
)

target_compile_features(main 
    PRIVATE
        cxx_std_17
)



#Defining subfiles
add_library(BoardRender)

target_sources(BoardRender
    PRIVATE
        src/BoardRender.cc
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/BoardRender.h
)

target_link_libraries(BoardRender
    PUBLIC
        sfml-graphics
)

target_link_libraries(main 
    PRIVATE
        sfml-graphics
        BoardRender
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)



