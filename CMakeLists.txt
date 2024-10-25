cmake_minimum_required(VERSION 3.28.2)
project(graphics-engine VERSION 1.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB SOURCE ${PROJECT_SOURCE_DIR}/src/*.cpp)
set(INCLUDE "${PROJECT_SOURCE_DIR}/include")
set(DEPENDENCIES "${PROJECT_SOURCE_DIR}/external")

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(graphics-engine
    ${SOURCE}
    ${DEPENDENCIES}/glad/glad.c
)

target_link_libraries(graphics-engine
    glfw
    OpenGL::GL 
)

target_include_directories(graphics-engine PUBLIC
    ${INCLUDE}
    ${DEPENDENCIES}
)