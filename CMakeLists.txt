 
cmake_minimum_required(VERSION 3.1)
project(test)

# 查找 OpenCV 库
find_package(OpenCV REQUIRED)

# 添加头文件路径
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加源文件
add_executable(test test.cpp)

# 链接库
target_link_libraries(test ${OpenCV_LIBS})
