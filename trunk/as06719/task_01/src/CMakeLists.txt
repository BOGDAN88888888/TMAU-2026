cmake_minimum_required(VERSION 3.10)

project(ControlModels LANGUAGES CXX)

# Стандарт языка C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Список исходников вынесен отдельно — удобнее поддерживать
set(PROJECT_SOURCES
    main.cpp
    InputSignal.cpp
    Model1_9.cpp
    Model2_3.cpp
    Model3_7.cpp
)

# Целевой исполняемый файл
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})