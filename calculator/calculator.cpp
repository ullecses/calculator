#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

enum Operation {
    sum,
    sub,
    // mul,
    // div,
    neg, // -x
    // exp,
    // log,
    // sqrt,
    // pow,
};

static map<string, Operation> s_mapOperation;



// User input
static char szInput[_MAX_PATH];

Operation askForOperation() {
    s_mapOperation["sum"] = sum;
    s_mapOperation["sub"] = sub;
    s_mapOperation["neg"] = neg;

    string operation;

    cout << "Please enter the operation:" << endl;

    cin.getline(szInput, _MAX_PATH);

    return s_mapOperation[szInput];
}

bool isUnary(Operation operation) {
    vector<Operation> unary_operations = { neg };
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
        case neg:
            return -operand;
        default:
            cout << "Wrong operation!" << endl;
    }
}

double applyBinaryOperation(Operation operation, double operand_1, double operand_2) {
    switch (operation) {
        case sum:
            return operand_1 + operand_2;
        case sub:
            return operand_1 - operand_2;
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
