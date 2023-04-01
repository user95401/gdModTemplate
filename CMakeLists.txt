cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
cmake_policy(SET CMP0057 NEW)

project ("mod")

file(GLOB_RECURSE SOURCE_FILES src/*.cpp ../curly-eureka/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE
  ../curly-eureka/minhook/include
  ../curly-eureka/gd.h/include
  ../curly-eureka/gd.h
  ../curly-eureka
)
add_subdirectory(../curly-eureka/cocos-headers cocos-headers-build)
add_subdirectory(../curly-eureka/minhook minhook-build)
target_link_libraries(${PROJECT_NAME} minhook cocos2d)