#include "rpn.h"
#include <sstream>
#include <stack>
#include <stdexcept>
#include <iostream>

double evaluate_rpn(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<double> stack;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::invalid_argument("Not enough operands for operator: " + token);
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();

            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::invalid_argument("Division by zero");
                stack.push(a / b);
            }
        } else {
            try {
                double num = std::stod(token);
                stack.push(num);
            } catch (...) {
                throw std::invalid_argument("Invalid token: " + token);
            }
        }
    }

    if (stack.size() != 1) {
        throw std::invalid_argument("Invalid expression");
    }

    return stack.top();
}