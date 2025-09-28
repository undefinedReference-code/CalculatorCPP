# 仅在启用测试时构建
if(BUILD_TESTING)
    # 创建测试可执行文件
    add_executable(calculator_tests test_calculator.cpp)
    target_link_libraries(calculator_tests PRIVATE calculator_lib gtest_main)

    # 注册测试用例
    add_test(NAME CalculatorTests COMMAND calculator_tests)
endif()