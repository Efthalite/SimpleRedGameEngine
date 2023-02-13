cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(stb)

add_library(${PROJECT_NAME} STATIC "stb_image.cpp")
target_include_directories(${PROJECT_NAME} PUBLIC ".")
