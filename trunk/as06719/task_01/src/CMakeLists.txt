cmake_minimum_required(VERSION 3.10)

project(ControlModels LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ИСПОЛЬЗУЕМ АВТОПОИСК:
# Это заставит CMake искать файлы и рядом с CMakeLists.txt, и в папке src/
file(GLOB PROJECT_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(ControlModels_as06719 ${PROJECT_SOURCES})

# Если это твой компьютер, называем файл ControlModels.exe, чтобы батник работал
if(NOT DEFINED ENV{GITHUB_ACTIONS})
    set_target_properties(ControlModels_as06719 PROPERTIES OUTPUT_NAME "ControlModels")
endif()