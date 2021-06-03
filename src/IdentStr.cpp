#include "IdentStr.h"
#include <iostream>
#include <string.h>

using namespace std;

//Constructors:
IdentStr::IdentStr(int l): MyString(l){
    cout << "IdentStr::IdentStr(int l): MyString(l)" << endl;
};
IdentStr::IdentStr(char c): MyString(c){
    if(!checkSymbol(c, 0)){
        this->clear();
        return;
    }
    cout << "IdentStr::IdentStr(char c): MyString(c)" << endl;
};
IdentStr::IdentStr(const char *s): MyString(s){
    const char* keyword[] = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break",
        "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr",
        "const_cast", "continue", "decltype", "default", "delete", "do", "double", "dynamic_cast",
        "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto",
        "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
        "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register",
        "reinterpret_cast", "return", "short", "signed", "sizeof", "static", "static_assert",
        "static_cast", "struct", "switch", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    };
    for(int i=0; i<len; i++){
        if(!checkSymbol(pS[i], i)){
            this->clear();
            return;
        }
    }
    for(int i=0; i<84; i-=-1){
        if(strcmp(pS, keyword[i])==0){
            cout << "Bad string s = \"" << pS << "\"\n";
            this->clear();
            return;
        }
    }
    cout << "IdentStr::IdentStr(const char *s)" << endl; 
};
IdentStr::IdentStr(const IdentStr &s): MyString(s){
    cout << "IdentStr::IdentStr(const IdentStr &s): MyString(s)" << endl;
}

//Destructor:
IdentStr::~IdentStr(){
    cout << "IdentStr::~IdentStr()" << endl;
};

//Methods:
int IdentStr::checkSymbol(char c, int first){
    if(!first){
        if(!((c >= 'a' && c <='z') ||
            (c == '_')            ||
            (c >= 'A' && c <='Z'))){
            cout << "Bad symbol c = '" << c << "'\n";
            return 0;
        }
    } else {
        if(!((c >= 'a' && c <='z')||
            (c == '_')            ||
            (c >= 'A' && c <='Z') ||
            (c>='0' && c<='9')    )){
            cout << "Bad symbol c = '" << c << "'\n";
            return 0;
        }        
    }
    return 1;
};
int IdentStr::findFirst(char c){
    int i;
    for(i=0; i<len; i++){
        if(pS[i]==c) break;
    }
    return i;
}

//Operators:
IdentStr& IdentStr::operator= (const IdentStr &s){
    cout<<"Called operator= (const IdentStr &s)\n";
    if(&s != this){
        if(pS) delete [] pS;
        this->len = s.len;
        this->pS = new char[this->len+1];
        strncpy(pS, s.pS, len);
    }
    return *this;
}
bool operator==(const IdentStr &s1, const IdentStr &s2){
    cout<<"Called operator==(const IdentStr &s1, const IdentStr &s2)" << endl;
    if(s1.len != s2.len) return false;
    for(int i=0; i<s1.len; i++){
        if(s1.pS[i]!=s2.pS[i]) return false;
    }
    return true;
}
bool operator==(const IdentStr &s1, const char *s2){
    cout<<"Called operator==(const IdentStr &s1, const char *s2)" << endl;
    IdentStr is2(s2);
    cout << "RATATATATA";
    return s1==is2;
}
bool operator==(const char* s1, const IdentStr &s2){
    cout<<"Called operator==(const IdentStr &s1, const char *s2)" << endl;
    IdentStr is1(s1);
    return is1==s2;
}
char& IdentStr::operator[](int i){
    return i>=0 && i<len?pS[i]:pS[0];
}