cmake_minimum_required(VERSION 3.20)
project(GitProject LANGUAGES CXX)

# Подключаем подпапки, где есть свои CMakeLists.txt
add_subdirectory(Home)
add_subdirectory(lessons)
add_subdirectory(prj.codeforces)
