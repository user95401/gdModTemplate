cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
cmake_policy(SET CMP0057 NEW)

project ("mod")

#curly-eureka
file(GLOB_RECURSE curly_eureka_src ../curly-eureka/*.cpp)
set(curly_eureka_incl ../curly-eureka/minhook/include ../curly-eureka/gd.h/include ../curly-eureka/gd.h ../curly-eureka)
add_subdirectory(../curly-eureka/cocos-headers cocos-headers-build)
add_subdirectory(../curly-eureka/minhook minhook-build)

#mod
file(GLOB_RECURSE src src/*)
add_library(${PROJECT_NAME} SHARED ${src} ${curly_eureka_src})
target_include_directories(${PROJECT_NAME} PRIVATE ${curly_eureka_incl})
target_link_libraries(${PROJECT_NAME} minhook cocos2d)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)