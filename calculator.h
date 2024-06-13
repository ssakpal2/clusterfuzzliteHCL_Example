#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
private:
    int precision;  // Precision for floating-point results

public:
    Calculator();  // Constructor

    void configure(int precision);  // Configure calculator precision

    double add(double a, double b);  // Addition operation
    double subtract(double a, double b);  // Subtraction operation
    double multiply(double a, double b);  // Multiplication operation
    double divide(double a, double b);  // Division operation
};

#endif // CALCULATOR_H
