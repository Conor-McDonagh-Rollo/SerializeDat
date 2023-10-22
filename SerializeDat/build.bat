@echo off
rem Build the project using Makefile
make

rem Check if the build was successful (Make may return a non-zero exit code on failure)
if %errorlevel% neq 0 (
    echo Build failed.
    pause
    exit /b %errorlevel%
)

rem Execute the program
.\build\test.exe

rem Pause to keep the console window open so you can see program output
pause