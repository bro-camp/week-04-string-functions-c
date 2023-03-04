@echo off
REM This file should only be used with VSCode Tasks

REM Get command line arguments
REM Do not put spaces between '=' symbol
set build_file_path=%~f1
set include_dir=%~f2
set src_file_path=%~f3

REM Then recreate build directory.
if not exist "./build/" (mkdir "./build/")

REM Then build the file.
REM For debugging
REM @echo on
gcc -o %build_file_path% -I %include_dir% %src_file_path%
