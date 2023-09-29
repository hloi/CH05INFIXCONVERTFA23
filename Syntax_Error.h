//
// Created by hloi on 9/22/2023.
//

#ifndef CH05INFIXCONVERTFA23_SYNTAX_ERROR_H
#define CH05INFIXCONVERTFA23_SYNTAX_ERROR_H
#include <stdexcept>
class Syntax_Error : public std::invalid_argument {
public:
    Syntax_Error(std::string msg) : std::invalid_argument(msg) {}
};
#endif //CH05INFIXCONVERTFA23_SYNTAX_ERROR_H
