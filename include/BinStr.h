#ifndef BINSTR_H
#define BINSTR_H
#pragma once
#include <MyString.h>

class BinStr : public MyString{
public:
    BinStr(int l = 0);
    BinStr(char c);
    BinStr(const char *s);
    BinStr(const BinStr &s);

    virtual ~BinStr();

    bool checkSymbol(char c);
    void invert();

    BinStr& operator= (const BinStr &s);
    char& operator[](int i);
    friend bool operator== (const BinStr &s1, const BinStr &s2);
};

#endif