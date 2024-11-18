@echo off
rem Check if main filename is provided
if "%1"=="" (
    echo Please provide the main file name without extension.
    exit /b
)

rem Set SFML include and lib directories
set SFML_INCLUDE=C:\SFML-Progs\SFML-2.5.1\SFML-2.5.1\include
set SFML_LIB=C:\SFML-Progs\SFML-2.5.1\SFML-2.5.1\lib

rem Compile main.cpp
g++ -c %1.cpp -I%SFML_INCLUDE% -std=c++17
if %errorlevel% neq 0 (
    echo Compilation failed for %1.cpp.
    exit /b
)

rem Compile LoginScreen.cpp
g++ -c LoginScreen.cpp -I%SFML_INCLUDE% -std=c++17
if %errorlevel% neq 0 (
    echo Compilation failed for LoginScreen.cpp.
    exit /b
)

rem Compile SignupScreen.cpp
g++ -c SignupScreen.cpp -I%SFML_INCLUDE% -std=c++17
if %errorlevel% neq 0 (
    echo Compilation failed for SignupScreen.cpp.
    exit /b
)

rem Link all object files
g++ %1.o LoginScreen.o SignupScreen.o -o %1 -L%SFML_LIB% -lsfml-graphics -lsfml-window -lsfml-system

rem Notify if linking was successful
if %errorlevel% equ 0 (
    echo Linking successful.
    echo Executable created: %1.exe
) else (
    echo Linking failed.
    exit /b
)
