cmake_minimum_required(VERSION 3.10)

project(ControlModels LANGUAGES CXX)

# Стандарт языка C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Список исходников (лежат в подпапке src/)
set(PROJECT_SOURCES
    src/main.cpp
    src/InputSignal.cpp
    src/Model1_9.cpp
    src/Model2_3.cpp
    src/Model3_7.cpp
)

# Целевой исполняемый файл
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})