#pragma once

#include <iostream>
#include <algorithm>

class Parser {
public:
    Parser(char init) {
        lookahead = init;
    }

    void expr() {
        term();
        while (true) {
            if (lookahead == '+') {
                match('+');
                term();
                std::cout<<"+";
            }
            else if (lookahead == '-') {
                match('-');
                term();
                std::cout<<"-";
            }
            else {
                return;
            }
        }

    }

    void term() {
        if (std::isdigit(lookahead)) {
            std::cout<<lookahead;
            match(lookahead);
        }
        else {
            std::cout<<"Syntax Error!"<<std::endl;
        }
    }

    void match(char t) {
        if (lookahead == t) {
            std::cin>>lookahead;
        }
        else {
            std::cout<<"Syntax Error!"<<std::endl;
        }
    }
public:
    char lookahead;
};