cmake_minimum_required(VERSION 3.10)

project(ControlModels LANGUAGES CXX)

# Стандарт языка C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Список исходников
set(PROJECT_SOURCES
    src/main.cpp
    src/InputSignal.cpp
    src/Model1_9.cpp
    src/Model2_3.cpp
    src/Model3_7.cpp
)

# Создаем цель с твоим уникальным именем (для проверки GitHub)
add_executable(ControlModels_as06719 ${PROJECT_SOURCES})

# ХИТРОСТЬ: Если сборка идет НЕ на GitHub Actions, переименовываем обратно в ControlModels.exe
if(NOT DEFINED ENV{GITHUB_ACTIONS})
    set_target_properties(ControlModels_as06719 PROPERTIES OUTPUT_NAME "ControlModels")
endif()