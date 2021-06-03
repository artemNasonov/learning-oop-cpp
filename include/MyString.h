#ifndef MYSTRING_H
#define MYSTRING_H

#pragma once
class MyString{
protected: 
    int len;
    char* pS;
public:
    MyString(int l = 0);
    MyString(const char *str);
    MyString(char c);
    MyString(const MyString &s);
    virtual ~MyString(); 

    void clear();
    void show();
    int getLen();
    char *getStr();
};


#endif