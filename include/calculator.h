#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>

/**
 * @brief 将数学表达式字符串分解为tokens
 * @param s 输入的数学表达式字符串
 * @return 分解后的token向量
 */
std::vector<std::string> tokenizer(std::string s);

/**
 * @brief 计算分解后的数学表达式
 * @param equation token化的数学表达式
 * @return 计算结果
 */
double calculate(std::vector<std::string> equation);

/**
 * @brief 直接计算数学表达式字符串（便捷函数）
 * @param expression 数学表达式字符串
 * @return 计算结果
 */
double calculateExpression(const std::string& expression);

#endif // CALCULATOR_H