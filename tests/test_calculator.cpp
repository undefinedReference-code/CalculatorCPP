#include <gtest/gtest.h>
#include "calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code here if needed
    }

    void TearDown() override {
        // Cleanup code here if needed
    }
};

// 测试基本的算术运算
TEST_F(CalculatorTest, BasicArithmetic) {
    EXPECT_DOUBLE_EQ(calculateExpression("2 + 3"), 5.0);
    EXPECT_DOUBLE_EQ(calculateExpression("10 - 4"), 6.0);
    EXPECT_DOUBLE_EQ(calculateExpression("3 * 4"), 12.0);
    EXPECT_DOUBLE_EQ(calculateExpression("15 / 3"), 5.0);
}

// 测试运算符优先级
TEST_F(CalculatorTest, OperatorPrecedence) {
    EXPECT_DOUBLE_EQ(calculateExpression("2 + 3 * 4"), 14.0);  // 2 + (3 * 4)
    EXPECT_DOUBLE_EQ(calculateExpression("10 - 2 * 3"), 4.0);  // 10 - (2 * 3)
    EXPECT_DOUBLE_EQ(calculateExpression("20 / 4 * 2"), 10.0); // (20 / 4) * 2
}

// 测试括号
TEST_F(CalculatorTest, Parentheses) {
    EXPECT_DOUBLE_EQ(calculateExpression("(2 + 3) * 4"), 20.0);
    EXPECT_DOUBLE_EQ(calculateExpression("2 * (3 + 4)"), 14.0);
    EXPECT_DOUBLE_EQ(calculateExpression("(10 - 2) / 4"), 2.0);
    EXPECT_DOUBLE_EQ(calculateExpression("4 + (1+2) * 3"), 13.0);
}

// 测试复杂表达式
TEST_F(CalculatorTest, ComplexExpressions) {
    EXPECT_DOUBLE_EQ(calculateExpression("100 * 2 + 12"), 212.0);
    EXPECT_DOUBLE_EQ(calculateExpression("100 * ( 2 + 12 )"), 1400.0);
    EXPECT_DOUBLE_EQ(calculateExpression("100 * ( 2 + 12 ) / 14"), 100.0);
}

// 测试负数
TEST_F(CalculatorTest, NegativeNumbers) {
    EXPECT_DOUBLE_EQ(calculateExpression("-5"), -5.0);
    EXPECT_DOUBLE_EQ(calculateExpression("1-(     -2)"), 3.0);
    EXPECT_DOUBLE_EQ(calculateExpression("(-3) + 5"), 2.0);
    EXPECT_DOUBLE_EQ(calculateExpression("10 + (-5)"), 5.0);
}

// 测试浮点数
TEST_F(CalculatorTest, FloatingPoint) {
    EXPECT_DOUBLE_EQ(calculateExpression("2.5 + 1.5"), 4.0);
    EXPECT_DOUBLE_EQ(calculateExpression("3.14 * 2"), 6.28);
    EXPECT_NEAR(calculateExpression("22.0 / 7.0"), 3.142857, 0.000001);
}

// 测试空格处理
TEST_F(CalculatorTest, WhitespaceHandling) {
    EXPECT_DOUBLE_EQ(calculateExpression("2+3"), 5.0);
    EXPECT_DOUBLE_EQ(calculateExpression("  2  +  3  "), 5.0);
    EXPECT_DOUBLE_EQ(calculateExpression("2 * ( 3 + 4 )"), 14.0);
}

// 测试tokenizer函数
TEST_F(CalculatorTest, TokenizerFunction) {
    auto tokens = tokenizer("2 + 3 * 4");
    std::vector<std::string> expected = {"2", "+", "3", "*", "4"};
    EXPECT_EQ(tokens, expected);
    
    tokens = tokenizer("(1 + 2) * 3");
    expected = {"(", "1", "+", "2", ")", "*", "3"};
    EXPECT_EQ(tokens, expected);
    
    tokens = tokenizer("-5 + 3");
    expected = {"0", "-", "5", "+", "3"};
    EXPECT_EQ(tokens, expected);
}

// 测试边界情况
TEST_F(CalculatorTest, EdgeCases) {
    EXPECT_DOUBLE_EQ(calculateExpression("0"), 0.0);
    EXPECT_DOUBLE_EQ(calculateExpression("42"), 42.0);
    EXPECT_DOUBLE_EQ(calculateExpression("((((5))))"), 5.0);
}