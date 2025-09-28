cmake_minimum_required(VERSION 3.15)
project(CalculatorProject LANGUAGES CXX)

# 全局设置
set(CMAKE_CXX_STANDARD 17)
include_directories(include)  # 全局头文件路径

# 启用测试开关（默认ON）
option(BUILD_TESTING "Enable tests" ON)
enable_testing()

# 添加子目录
add_subdirectory(src)
add_subdirectory(tests)  # 测试目录有条件构建