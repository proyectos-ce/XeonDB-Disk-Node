cmake_minimum_required(VERSION 2.8)

project(DiskNode)

find_package(Boost)
IF (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIR})
endif()

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        table.h table.cpp
        filemanager.h filemanager.cpp
        connectionManager.cpp connectionManager.h
        jsonutils.h jsonutils.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries ("DiskNode" ${Boost_LIBRARIES})
