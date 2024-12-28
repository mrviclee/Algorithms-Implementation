cmake_minimum_required(VERSION 3.15)
project(MinimumSpanningTree LANGUAGES CXX)

#C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find graphviz headers
find_path(GRAPHVIZ_INCLUDE_DIR
    NAME graphviz/gvc.h
    PATHS /opt/homebrew/include /usr/include /usr/local/include
)

# Fidn graphviz gvc library
find_library(GRAPHVIZ_GVC_LIBRARY
    NAME gvc
    PATHS /opt/homebrew/lib /usr/lib /usr/local/lib
)


# Find graphviz cdt library
find_library(GRAPHVIZ_CDT_LIBRARY
    NAME cdt
    PATHS /opt/homebrew/lib /usr/lib /usr/local/lib
)

message(STATUS "GRAPHVIZ_INCLUDE_DIR: ${GRAPHVIZ_INCLUDE_DIR}")
message(STATUS "GRAPHVIZ_GVC_LIBRARY: ${GRAPHVIZ_GVC_LIBRARY}")
message(STATUS "GRAPHVIZ_CDT_LIBRARY: ${GRAPHVIZ_CDT_LIBRARY}")

if (NOT GRAPHVIZ_INCLUDE_DIR)
    message(FATAL_ERROR "Graphviz header not found! Please install Graphviz or specify its location.")
endif()
if (NOT GRAPHVIZ_GVC_LIBRARY)
    message(FATAL_ERROR "Graphviz gvc library not found! Please install Graphviz or specify its location.")
endif()
if (NOT GRAPHVIZ_CDT_LIBRARY)
    message(FATAL_ERROR "Graphviz cdt not found! Please install Graphviz or specify its location.")
endif()

include_directories(${GRAPHVIZ_INCLUDE_DIR})

# Include the header files
include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/Edge.cpp
    src/Graph.cpp
)

add_executable(MinimumSpanningTree ${SOURCES})

target_link_libraries(MinimumSpanningTree PRIVATE ${GRAPHVIZ_CDT_LIBRARY} ${GRAPHVIZ_GVC_LIBRARY})