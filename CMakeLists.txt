cmake_minimum_required(VERSION 3.16)
project(phlawless-engine)


include_directories(
  "${PROJECT_BINARY_DIR}"
  "${CMAKE_SOURCE_DIR}/source/core"
  "${CMAKE_SOURCE_DIR}/source/entites"
  )

# Define sources and executable
set(EXECUTABLE_NAME "phlawless-engine")
add_executable(${EXECUTABLE_NAME}
 main.cpp
 source/core/Engine.cpp
 source/core/Engine.h
 source/entities/Player.h
 source/entities/Player.cpp
 )


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5.1 REQUIRED system window graphics network audio)
# target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(phlawless-engine sfml-system sfml-window sfml-graphics sfml-network sfml-audio)


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
