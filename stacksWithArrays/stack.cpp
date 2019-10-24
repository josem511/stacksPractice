#include<iostream>
int const MAXSIZE = 500;

char get_top(char* myS, int sp){
    return myS[sp];
}

void push(char* myS, int& sp, char v){
    if (sp < MAXSIZE)
        myS[++sp] = v;
    else
        std::cout << "Stack is full";
}

char pop(char* myS, int& sp){
    if (sp > -1)
        return myS[sp--];
    sp--;
    return '0';
}

int get_size(char* myS, int sp){
    return sp+1;
}
