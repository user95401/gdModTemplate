cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /MANIFEST:NO")
cmake_policy(SET CMP0057 NEW)

project ("mod")

#curly-eureka
include(C:\\Users\\Lenovo\\source\\curly-eureka\\CURLY-EUREKA-INCL.cmake)

#mod
file(GLOB_RECURSE src src/*)
add_library(${PROJECT_NAME} SHARED ${src} ${curly_eureka_src})

#put release in gd mods folder. (FUCKS Release/Debug folder)
set(LIBRARY_OUTPUT_PATH "D:/Games/user666/Geometry.Dash.v07.24.2021/adaf-dll")