cmake_minimum_required(VERSION 3.16)
project(phlawless-engine)


include_directories(
  "${PROJECT_BINARY_DIR}"
  "${CMAKE_SOURCE_DIR}/source/header"
  "${CMAKE_SOURCE_DIR}/source/cpp"
  )

# Define sources and executable
set(EXECUTABLE_NAME "phlawless-engine")
add_executable(${EXECUTABLE_NAME}
 main.cpp
 source/cpp/Engine.cpp
 source/header/Engine.h
 )


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5.1 REQUIRED system window graphics network audio)
# target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(phlawless-engine sfml-system sfml-window sfml-graphics sfml-network sfml-audio)


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
