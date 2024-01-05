@echo off
cls
cmake -G "MinGW Makefiles" ./

mingw32-make

echo "Build complete"
echo ""

tronicstore.exe input.txt

pause

del cmake_install.cmake
del CMakeCache.txt
rd /s /q "CMakeFiles"