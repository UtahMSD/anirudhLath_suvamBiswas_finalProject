# cmake_minimum_required(VERSION <specify CMake version here>)
project(FinalProjectCS6010)

set(CMAKE_CXX_STANDARD 14)

include_directories(c:/SFML/include)
add_executable(FinalProjectCS6010
        helper.cpp
        helper.hpp
        main.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(FinalProjectCS6010 ${SFML_LIBRARIES})
endif ()

if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})

endif ()


