@echo off
setlocal

:: Переходим в папку, где лежит сам батник
cd /d "%~dp0"

:: 1. Принудительно закрываем старые процессы, чтобы папка build не была занята
taskkill /F /IM ControlModels.exe /T >nul 2>&1
taskkill /F /IM mingw32-make.exe /T >nul 2>&1

:: 2. Удаляем старую папку сборки
if exist build (rmdir /s /q build)
mkdir build

:: 3. Создаем папку doc, если её нет (чтобы программа могла сохранить CSV)
if not exist doc (mkdir doc)

:: 4. Создаем копию make.exe в w64devkit, чтобы CMake не ругался
if not exist "D:\qw\w64devkit\bin\make.exe" (
    copy "D:\qw\w64devkit\bin\mingw32-make.exe" "D:\qw\w64devkit\bin\make.exe" >nul
)

:: 5. Добавляем компиляторы в PATH для текущей сессии
set PATH=D:\qw\w64devkit\bin;%PATH%

cd build

echo ===================================================
echo [STEP 1/3] Configuring project via CMake (Ninja)...
echo ===================================================
"C:\Program Files\CMake\bin\cmake.exe" .. -G "Ninja" -DCMAKE_C_COMPILER=gcc.exe -DCMAKE_CXX_COMPILER=g++.exe -DCMAKE_BUILD_TYPE=Release
if %errorlevel% neq 0 (
    echo [ERROR] CMake configuration failed.
    goto end
)

echo.
echo ===================================================
echo [STEP 2/3] Building project modules...
echo ===================================================
"C:\Program Files\CMake\bin\cmake.exe" --build .
if %errorlevel% neq 0 (
    echo [ERROR] Compilation failed.
    goto end
)

echo.
echo ===================================================
echo [STEP 3/3] Running simulation (Variant 19)...
echo ===================================================
ControlModels.exe

echo.
echo ===================================================
echo Generating and opening graph automatically...
echo ===================================================
cd ..
py src\plot.py

:end
echo.
echo ===================================================
echo Process finished. Press any key to exit.
echo ===================================================
pause
endlocal