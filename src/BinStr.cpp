#include "BinStr.h"
#include <iostream>
#include <string.h>

using namespace std;

//Constructors:
BinStr::BinStr(int l): MyString(l){
    cout<<"BinStr::BinStr(int l): MyString(l)\n";
}
BinStr::BinStr(char c): MyString(c){
    if(!checkSymbol(c)){
        cout<<"Wrong symbol c = '"<<c<<"'\n";
        this->clear();
        return;
    }
    cout<<"BinStr::BinStr(char c): MyString(c)\n";
}
BinStr::BinStr(const char *s): MyString(s){
    for(int i=0; i<len; i++){
        if(!checkSymbol(pS[i])){
            cout<<"Wrong symbol pS["<<i<<"] = '"<<pS[i]<<"'\n";
            this->clear();
            return;
        }
    }
    cout<<"BinStr::BinStr(const char *s): MyString(s)\n";
}
BinStr::BinStr(const BinStr &s): MyString(s){
    cout<<"BinStr::BinStr(const BinStr &s): MyString(s)\n";
}

//Destructor:
BinStr::~BinStr(){
    cout << "BinStr::~BinStr()" << endl;
}

//Methods:
bool BinStr::checkSymbol(char c){
    return (c=='1' || c=='0');
}
void BinStr::invert(){
    for(int i=0; i<len; i++){
        pS[i]^=1;
    }
}

//Operators:
BinStr& BinStr::operator= (const BinStr &s){
    cout << "Called operator= (const BinStr &s)\n";
    if(&s!=this){
        if(pS) delete[] pS;
        this->len = s.len;
        this->pS = new char[this->len];
        strncpy(pS, s.pS, len);
    }
    return *this;
}
char& BinStr::operator[](int i){
    return (i>=0 && i<len)?pS[i]:pS[0];
}

bool operator==(const BinStr &s1, const BinStr &s2){
    if(s1.len != s2.len) return false;
    for(int i=0; i<s1.len; i++){
        if(s1.pS[i]!=s2.pS[i]) return false;
    }
    return true;
}