//
// Created by hloi on 9/22/2023.
//

#include "Postfix_Evaluator.h"


#include <sstream>
#include <cctype>
using std::stack;
using std::string;
using std::istringstream;
using std::isdigit;
const std::string Postfix_Evaluator::OPERATORS = "+-*/";

/**
@param expression The expression to be evaluated
@return The value of the expression
@throws Syntax_Error if a syntax error is detected
*/
double Postfix_Evaluator::eval(const std::string& expression) {
// Be sure the stack is empty
    while (!operand_stack.empty())
        operand_stack.pop();
// Process each token
    istringstream tokens(expression);  // 4 |7 |* |20 |-
    char next_char;
    while (tokens >> next_char) {
        if (isdigit(next_char)) {
            tokens.putback(next_char);
            double value;
            tokens >> value;  // convert input into a numeric value
            operand_stack.push(value);
        } else if (is_operator(next_char)) {
            double result = eval_op(next_char); //pass in the op
            operand_stack.push(result);
        } else {
            throw Syntax_Error("Invalid character encountered");
        }
    }
    if (!operand_stack.empty()) {
        double answer = operand_stack.top();
        operand_stack.pop();
        if (operand_stack.empty()) {
            return answer;
        } else {
            throw Syntax_Error("Stack should be empty");
        }
    } else {
        throw Syntax_Error("Stack is empty");
    }
}

/** Evaluates the current operator.
This function pops the two operands off the operand
stack and applies the operator.
@param op A character representing the operator
@throws Syntax_Error if top is attempted on an empty stack
*/
double Postfix_Evaluator::eval_op(char op) {
    if (operand_stack.empty())
        throw Syntax_Error("Stack is empty");
    double rhs = operand_stack.top();
    operand_stack.pop();
    if (operand_stack.empty())
        throw Syntax_Error("Stack is empty");
    double lhs = operand_stack.top();
    operand_stack.pop();
    double result = 0;
    switch(op) {
        case '+' : result = lhs + rhs;
            break;
        case '-' : result = lhs - rhs;
            break;
        case '*' : result = lhs * rhs;
            break;
        case '/' : result = lhs / rhs;
            break;
    }
    return result;
}