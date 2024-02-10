#include <iostream>

double calculate(double num1, double num2, char operation) {
    switch (operation) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/':
        if (num2 != 0) {
            return num1 / num2;
        }
        throw std::string("Error: Division by zero '0' is not allowed");
    case '%':
        int iNum1, iNum2;
        iNum1 = static_cast<int>(num1);
        iNum2 = static_cast<int>(num2);

        if (iNum1 == num1 && iNum2 == num2) {
            return iNum1 % iNum2;
        }
        throw std::string("Error: modulo operation '%' with non-integer number is not allowed\n");
    default: throw std::string("Error: Invalid operator '" + std::string(1, operation) + "'\n");
    }
}

int main() {
    double num1, num2;
    char operation;
    std::cout << "Enter a valid expression\n";
    std::cin >> num1 >> operation >> num2;
    
    try {
        double result = calculate(num1, num2, operation);
        std::cout << "Result = " << result << '\n';
    }
    catch(std::string& e) {
        std::cerr << e << '\n';
    }
}