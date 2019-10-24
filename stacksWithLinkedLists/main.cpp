#include "node.cpp"
#include "Stack.hpp"
#include<iostream>

int main(){
    Stack<char> s;
    std::string name;
    std::cout << s.getSize() << std::endl;
    std::cout << "What's your name? ";
    std::cin >> name;
    for (char c: name)
        s.push(c);
    std::cout << s.getSize() << std::endl;
    while (s.getSize() > 0){
        std::cout << s.getTop() << std::endl;
        s.pop();
    }
    return 0;
}