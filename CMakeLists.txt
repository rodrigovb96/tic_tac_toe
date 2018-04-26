#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 3.0)


# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(tic-tac-toe)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++1z") 


include_directories("${PROJECT_SOURCE_DIR}/include" 
					"${PROJECT_SOURCE_DIR}/src")


message( ${PROJECT_SOURCE_DIR} )

# Define sources and executable
set(EXECUTABLE_NAME "tic-tac-toe")

add_executable(${EXECUTABLE_NAME} src/main.cpp)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2.4 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


