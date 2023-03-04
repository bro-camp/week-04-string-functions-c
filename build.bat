@echo off
REM Remove build directory if it already exists.
if exist "./build/" (rmdir "./build/" /s /q)

REM Then recreate build directory.
if not exist "./build/" (mkdir "./build/")

REM Then call python build script to build the project.
python build.py
