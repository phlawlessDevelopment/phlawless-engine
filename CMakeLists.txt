cmake_minimum_required(VERSION 3.16)
project(phlawless-engine)


include_directories(
  "${PROJECT_BINARY_DIR}"
  "${CMAKE_SOURCE_DIR}/include"
  "${CMAKE_SOURCE_DIR}/source/core"
  "${CMAKE_SOURCE_DIR}/source/scene"
  "${CMAKE_SOURCE_DIR}/source/components"
  )

# Define sources and executable
set(EXECUTABLE_NAME "phlawless-engine")
set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/include")

file(GLOB INCLUDES
"${CMAKE_SOURCE_DIR}/include/*.cpp"
"${CMAKE_SOURCE_DIR}/include/*.h"
)

add_executable(${EXECUTABLE_NAME}
${INCLUDES}
 main.cpp

 source/core/Editor.cpp
 source/core/Editor.h

 source/scene/Node.h
 source/scene/Node.cpp
 source/scene/Scene.h
 source/scene/Scene.cpp

 source/components/Component.h
 source/components/Component.cpp
 source/components/SpriteComponent.h
 source/components/SpriteComponent.cpp


 )


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5.1 REQUIRED system window graphics network audio)
find_package(OpenGL REQUIRED)
# target_link_libraries(phlawless-engine PRIVATE ImGui-SFML::ImGui-SFML)
# target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(phlawless-engine 
${OPENGL_LIBRARIES}
sfml-system
sfml-window
sfml-graphics
sfml-network
sfml-audio
)


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
