cmake_minimum_required(VERSION 3.20)
project(uMediator LANGUAGES CXX)

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
FetchContent_GetProperties(boost-di)

add_library(uMediator INTERFACE)

target_include_directories(uMediator
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${boost-di_SOURCE_DIR}/include>
)

include(GNUInstallDirs)

install(
        DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/umediatore"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/umediatore"
)

install(
        TARGETS uMediator
        EXPORT uMediatorTargets
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/uMediator"
)

install(
        EXPORT uMediatorTargets
        FILE uMediatorTargets.cmake
        NAMESPACE uMediator::
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/uMediator"
)
