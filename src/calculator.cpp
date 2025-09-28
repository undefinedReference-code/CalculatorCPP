#include "calculator.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cassert>
#include <cfloat>

static std::unordered_map<char, int> operatorList{
    std::pair<char, int> {'(', 0}, std::pair<char, int> {')', 0},
    std::pair<char, int> {'+', 1}, std::pair<char, int> {'-', 1},
    std::pair<char, int> {'*', 2}, std::pair<char, int>{'/', 2},
};

std::vector<std::string> tokenizer(std::string s) {
    std::string buffer;
    std::vector<std::string> res;

    if (s[0] == '-') {
        res.push_back("0");
    }

    for (int i = 0; i < s.size(); i++) {
        char cur = s[i];
        if (cur == ' ')
            continue;

        if (operatorList.find(cur) != operatorList.end()) {
            if (!buffer.empty())
                res.push_back(buffer);
            buffer.clear();
            res.push_back(std::string(1, cur));
        }
        else {
            buffer.push_back(cur);
        }
    }

    if (!buffer.empty()) {
        res.push_back(buffer);
    }

    return res;
}

static void PopTopOperation(std::vector<double>& numberStack, std::vector<char>& operatorStack) {
    char operation = operatorStack.back();
    operatorStack.pop_back();
    double op2 = DBL_MAX;
    double op1 = DBL_MAX;
    double res = DBL_MAX;
    switch (operation)
    {
    case '+' :
        op2 = numberStack.back(); numberStack.pop_back();
        op1 = numberStack.back(); numberStack.pop_back();
        res = op1 + op2;
        numberStack.push_back(res);
        break;
    case '-':
        op2 = numberStack.back(); numberStack.pop_back();
        op1 = numberStack.back(); numberStack.pop_back();
        res = op1 - op2;
        numberStack.push_back(res);
        break;
    case '*':
        op2 = numberStack.back(); numberStack.pop_back();
        op1 = numberStack.back(); numberStack.pop_back();
        res = op1 * op2;
        numberStack.push_back(res);
        break;
    case '/':
        op2 = numberStack.back(); numberStack.pop_back();
        op1 = numberStack.back(); numberStack.pop_back();
        res = op1 / op2;
        numberStack.push_back(res);
        break;
    default:
        break;
    }
}

double calculate(std::vector<std::string> equation) {
    std::vector<double> numberStack;
    std::vector<char> operatorStack;

    for (int i = 0; i < equation.size(); i++) {
        std::string token = equation[i];

        if (token[0] == '-' && (i==0 || equation[i-1][0] == '(') ){
            numberStack.push_back(0);
        }

        if (operatorList.find(token[0]) == operatorList.end()) {
            numberStack.push_back(std::stod(token));
        }
        else {
            if (token[0] == '(')
                operatorStack.push_back('(');
            else if (token[0] == ')') {
                while (!operatorStack.empty() && operatorStack.back() != '(') {
                    PopTopOperation(numberStack, operatorStack);
                }
                operatorStack.pop_back();
            }
            else {
                if (!operatorStack.empty() && operatorList[token[0]] <= operatorList[operatorStack.back()]) {
                    PopTopOperation(numberStack, operatorStack);
                }
                else {
                    operatorStack.push_back(token[0]);
                }
            }
        }
    }

    while (!operatorStack.empty()) {
        PopTopOperation(numberStack, operatorStack);
    }

    assert(numberStack.size() == 1);

    return numberStack.front();
}

double calculateExpression(const std::string& expression) {
    auto tokens = tokenizer(expression);
    return calculate(tokens);
}