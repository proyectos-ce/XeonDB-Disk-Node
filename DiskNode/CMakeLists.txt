cmake_minimum_required(VERSION 2.8)

project(DiskNode)

find_package(Boost)
IF (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIR})
endif()

set(SOURCE_FILES
    main.cpp
    row.h row.cpp
    datacontainer.h datacontainer.cpp
    table.h table.cpp
    )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries ("DiskNode" ${Boost_LIBRARIES})
