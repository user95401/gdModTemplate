cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /MANIFEST:NO")
cmake_policy(SET CMP0057 NEW)

project ("mod")
set(developer "user95401")
set(version "v1.0.0")
set(description "no description")
set(repository "https://github.com/user95401/gdModTemplate")
set(issues_url "https://discord.gg/89VGJH6QQg")
set(issues_info "U can write about it on <cb>user666's discord...</c>")
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_LIST_DIR}") # dll output
set(GEODE_MOD_OUTPUT_PATH "D:\\Games\\user666\\Geometry.Dash.v07.24.2021\\geode\\mods") # geode mod output

#curly-eureka
include("C:\\Users\\Lenovo\\source\\curly-eureka\\CURLY-EUREKA-INCL.cmake")# "\" must be escaped by \\

#mod
file(GLOB_RECURSE SRC
src/* 
src/Layers/*
)
add_library(${PROJECT_NAME} SHARED ${SRC} ${CURLY_EUREKA_SRC})

#geode-makeup
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/geode geode-build)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND #POST_BUILD UPDATE USES POWERSHELL!
"${CMAKE_CURRENT_LIST_DIR}/geode/CMakeCCUpdateBin.bat ${developer} > dev ${PROJECT_NAME} > proj ${CMAKE_CURRENT_LIST_DIR} > proj_dir ${LIBRARY_OUTPUT_PATH} > dll_out ${GEODE_MOD_OUTPUT_PATH} > geod_out")
