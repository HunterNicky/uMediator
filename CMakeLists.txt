cmake_minimum_required(VERSION 3.20)
project(uMediator LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
        boost-di
        GIT_REPOSITORY https://github.com/boost-ext/di.git
        GIT_TAG        v1.3.2
)
FetchContent_MakeAvailable(boost-di)

add_library(uMediator INTERFACE)

target_include_directories(uMediator
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(uMediator INTERFACE Boost.DI)