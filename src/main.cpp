
#include <iostream>
#include <string>
#include "calculator.h"

int main() {
    std::cout << "=== Calculator Demo ===" << std::endl;
    
    // 测试一些表达式
    std::string expressions[] = {
        "4 + (1+2) * 3",
        "1-(     -2)",
        "10 + 2 * 6",
        "100 * 2 + 12",
        "100 * ( 2 + 12 )",
        "100 * ( 2 + 12 ) / 14"
    };
    
    for (const auto& expr : expressions) {
        try {
            double result = calculateExpression(expr);
            std::cout << expr << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error calculating '" << expr << "': " << e.what() << std::endl;
        }
    }
    
    // 交互式计算器
    std::cout << "\n=== Interactive Calculator ===" << std::endl;
    std::cout << "Enter expressions to calculate (type 'quit' to exit):" << std::endl;
    
    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input == "quit" || input == "exit") {
            break;
        }
        
        if (input.empty()) {
            continue;
        }
        
        try {
            double result = calculateExpression(input);
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    
    std::cout << "Goodbye!" << std::endl;
    return 0;
}