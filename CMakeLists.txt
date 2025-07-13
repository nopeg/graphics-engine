cmake_minimum_required(VERSION 3.28.2)
project(graphics-engine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(COPY resources DESTINATION "${CMAKE_BINARY_DIR}/bin")

file(GLOB_RECURSE SOURCE_FILES 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/graphics/OpenGL/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/graphics/*.cpp"
)

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

# GLFW
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# GLM
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.0
)

# GLEW-CMake
FetchContent_Declare(
    glew
    GIT_REPOSITORY https://github.com/perlmint/glew-cmake.git
    GIT_TAG master
)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLEW_USE_STATIC_LIBS ON CACHE BOOL "" FORCE)

# STB Image
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb.git
    GIT_TAG master
)

FetchContent_MakeAvailable(glfw glm glew stb)

add_library(stb_image INTERFACE)
target_include_directories(stb_image INTERFACE ${stb_SOURCE_DIR})
target_compile_definitions(stb_image INTERFACE STB_IMAGE_IMPLEMENTATION)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/graphics"
    "${PROJECT_SOURCE_DIR}/include/graphics/OpenGL"
    "${glm_SOURCE_DIR}"
    "${glew_SOURCE_DIR}/include"
    "${glfw_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    libglew_static
    stb_image
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})