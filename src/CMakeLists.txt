# 生成核心逻辑静态库
add_library(calculator_lib STATIC calculator.cpp)
target_include_directories(calculator_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)  # 公开头文件路径

# 生成主程序
add_executable(calculator_app main.cpp)
target_link_libraries(calculator_app PRIVATE calculator_lib)  # 链接核心库