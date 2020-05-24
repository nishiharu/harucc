#include <iostream>
#include "Parser.hpp"
#include "Lexer.hpp"

int main(int argc, char** argv) {
    char lookahead;
    std::cin>>std::noskipws;
    std::cin>>lookahead;
    Parser parse(lookahead);
    parse.expr();
    std::cout<<std::endl;
}