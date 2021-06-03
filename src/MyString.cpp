#include "MyString.h"
#include <iostream>
#include <string.h>

using namespace std;

//Constructors:
MyString::MyString(int l): len(l), pS(new char[len+1]){
    pS[len]=0;
    cout << "MyString::MyString(int l);" << endl;
};
MyString::MyString(char c): len(1), pS(new char[2]){
    pS[0] = c;
    pS[1] = 0;
    cout << "MyString::MyString(char c);" << endl;
};
MyString::MyString(const char *s): len(strlen(s)), pS(new char[len+1]){
    for(int i=0; i<len; i++){
        pS[i] = s[i];
    }
    pS[len] = 0;
    cout << "MyString::MyString(const char *s);" << endl;
};
MyString::MyString(const MyString &s): len(s.len), pS(new char[len+1]){
    for(int i=0; i<len; i++){
        pS[i] = s.pS[i];
    }
    pS[len] = 0;
    cout << "MyString::MyString(const MyString &s);" << endl;
};
MyString::~MyString(){
    if (pS) delete[] pS;
    len=0;
    cout << "MyString::~MyString();" << endl;
};

//Getters:
int MyString::getLen(){
    return len;
};
char* MyString::getStr(){
    return pS;
};

//Methods:
void MyString::clear(){
    if(pS) delete[] pS;
    len = 0;
    pS = new char[1];
    pS[0] = 0;
};
void MyString::show(){
    cout << "pS = \"" << pS << 
            "\"\nlen = " << len << endl;
}