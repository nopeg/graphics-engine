cmake_minimum_required(VERSION 3.28.2)
project(graphics-engine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(COPY resources DESTINATION "${CMAKE_BINARY_DIR}/bin")

file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")


# Загрузка зависимостей
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

FetchContent_MakeAvailable(glfw glm glew)


# Исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Настройка include-директорий
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${glm_SOURCE_DIR}
    ${glew_SOURCE_DIR}/include
    ${glfw_SOURCE_DIR}/include
)

# Линковка библиотек
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    libglew_static
)

# Платформо-специфичные настройки
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
endif()

# Настройки компилятора
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Генерация файлов для IDE
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})