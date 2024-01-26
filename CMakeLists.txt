cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /MANIFEST:NO") # MANIFEST:NO yea
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_LIST_DIR}") # dll output
cmake_policy(SET CMP0057 NEW)

project ("mod")
set(developer "user95401")
set(description "Geometry Dash 2.113 Mod")
set(lib_output "D:\\Games\\user666\\Geometry.Dash.v07.24.2021\\fif issue\\") # post build copy

#curly-eureka
include("C:\\Users\\Lenovo\\source\\curly-eureka\\CURLY-EUREKA-INCL.cmake")# "\" must be escaped by \\

#mod
file(GLOB_RECURSE SRC
src/* 
src/Layers/*
#${CURLY_EUREKA_DIR} to include other stuff
)
add_library(${PROJECT_NAME} SHARED ${SRC} ${CURLY_EUREKA_SRC})

#POST_BUILD
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND #POST_BUILD UPDATE USES POWERSHELL!
"${CMAKE_CURRENT_LIST_DIR}/CMakePostBuild.bat" ${developer} ${PROJECT_NAME} ${LIBRARY_OUTPUT_PATH} ${lib_output})
