#ifndef IDENTSTR_H
#define IDENTSTR_H
#pragma once
#include <MyString.h>


class IdentStr : public MyString{
private:
    int checkSymbol(char c, int first = 0);
public:
    IdentStr(int l = 0);
    IdentStr(char c);
    IdentStr(const char *s);
    IdentStr(const IdentStr &s);
    virtual ~IdentStr();

    int findFirst(char c);
    IdentStr& operator= (const IdentStr &s);
    char& operator[](int i);
    friend bool operator== (const IdentStr &s1, const IdentStr &s2);
    friend bool operator== (const IdentStr &s1, const char *s2);
    friend bool operator== (const char *s1, const IdentStr &s2);
};

#endif