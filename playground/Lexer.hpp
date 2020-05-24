#pragma once

#include <string>
#include <algorithm>
#include <unordered_map>
//#include <map>

class Token {
public:
    Token(int t) :
        tag(t) {}
public:
    const int tag;
};

class Tag {
public:
    const static int 
        NUM = 256, ID = 257, TRUE = 258, FALSE = 259;
};

class Num : public Token {
public:
    Num(int v) : 
        Token(Tag::NUM), value(v) {}
public:
    const int value;
};

class Word : public Token {
public:
    Word() : 
        Token(0), lexeme("") {}
    Word(int t, std::string s) :
        Token(t), lexeme(s) {}
public:
    const std::string lexeme;
};

class Lexer {
public:
    Lexer() {
        reserve(Word(Tag::TRUE, "true"));
        reserve(Word(Tag::FALSE, "false"));
    }

    Token scan() {
        while (true) {
            if (peek == ' ' || peek == '\t') continue;
            else if (peek == '\n') ++line;
            else break;
            std::cin>>peek;
        }
            
        if (std::isdigit(peek)) {
            int v = 0;
            while (std::isdigit(peek)) {
                v = 10*v + static_cast<int>(peek - '0');
                std::cin>>peek;
            }
            return Num(v);
        }
        if (std::isalpha(peek)) {
            std::string s;
            while (std::isalnum(peek)) {
                s.push_back(peek);
                std::cin>>peek;
            }
            if (words.find(s) == words.end()) {
                words.insert(std::make_pair(s, Word(Tag::ID, s)));
            }
            return words[s];
        }

        Token t(peek);
        peek = ' ';
        return t;
    }
private:
    void reserve(Word t) {
        words.insert(std::make_pair(t.lexeme, t));
    }
public:
    int line = 1;
private:
    char peek = ' ';
    std::unordered_map<std::string, Word> words;
};