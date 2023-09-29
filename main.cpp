#include "Postfix_Evaluator.h"
//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//    Postfix_Evaluator postfix;
//    cout <<
//         "Enter expressions to be converted, or press Return when done\n";
//    string expression;
//    while (getline(cin, expression)) {
//        if (expression == "") break;
//        try {
//            int result = postfix.eval(expression);
//            cout << "== " << result << endl;
//        } catch (Syntax_Error& ex) {
//            cout << "Syntax Error: " << ex.what() << endl;
//        }
//        cout << "Enter next expression: ";
//    }
//}

/** Program to test the infix to postfix converter. */
#include "Infix_To_Postfix.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
    Infix_To_Postfix infix_to_postfix;
    cout <<
         "Enter expressions to be converted, or press Return when done\n";
    string expression;
    while (getline(cin, expression)) {
        if (expression == "") break;
        try {
            string result = infix_to_postfix.convert(expression);
            cout << "== " << result << endl;
            Postfix_Evaluator postfix;
            cout << postfix.eval(result) << endl;
        } catch (Syntax_Error& ex) {
            cout << "Syntax Error: " << ex.what() << endl;
        }
        cout << "Enter next expression: ";

    }
}