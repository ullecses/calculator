#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

enum Operation {
    Sum,
    Sub,
    Mul,
    Div,
    Neg, // -x
    Exp,
    Log,
    Sqrt,
    Pow,
};

static map<string, Operation> s_mapOperation;

Operation askForOperation() {
    string operation;

    s_mapOperation["sum"] = Sum;
    s_mapOperation["sub"] = Sub;
    s_mapOperation["neg"] = Neg;
    s_mapOperation["mul"] = Mul;
    s_mapOperation["div"] = Div;
    s_mapOperation["sqrt"] = Sqrt;
    s_mapOperation["exp"] = Exp;
    s_mapOperation["log"] = Log;
    s_mapOperation["pow"] = Pow;

    cout << "Please enter the operation:" << endl;

    cin >> operation;

    return s_mapOperation[operation];
}

bool isUnary(Operation operation) {
    vector<Operation> unary_operations = { Neg , Sqrt , Exp , Log };
    return find(unary_operations.begin(), unary_operations.end(), operation) != unary_operations.end();
}

int enterTheNumber() {
    int number;

    cout << "Please enter the number:" << endl;

    cin >> number;
    
    return number;
}

double applyUnaryOperation(Operation operation, double operand) {
    switch (operation) {
        case Neg:
            return -operand;
        case Sqrt:
            return std::sqrt(operand);
        case Exp:
            return std::exp(operand);
        case Log:
            return std::log(operand);
        default:
            cout << "Wrong operation!" << endl;
    }
}

double applyBinaryOperation(Operation operation, double operand_1, double operand_2) {
    switch (operation) {
        case Sum:
            return operand_1 + operand_2;
        case Sub:
            return operand_1 - operand_2;
        case Mul:
            return operand_1 * operand_2;
        case Div:
            return operand_1 / operand_2;
        case Pow:
            return pow(operand_1, operand_2);


        default:
            cout << "Wrong operation!" << endl;
    }
}

void printResult(double result) {
    cout << "Result of operation is " << result << "!" << endl;
}

int main()
{
    Operation operation;
    double number_1, number_2, result;

    operation = askForOperation();
    if (isUnary(operation)) {
        number_1 = enterTheNumber();
        result = applyUnaryOperation(operation, number_1);
    }
    else {
        number_1 = enterTheNumber();
        number_2 = enterTheNumber();
        result = applyBinaryOperation(operation, number_1, number_2);
    }

    printResult(result);
}
