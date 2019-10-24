#include<iostream>
#include<string>

#include "stack.cpp"

int main()
{
    char myStack[MAXSIZE];
    int sp = -1;
    std::string name;
    std::cout << "What's your name? ";
    std::cin >> name;
    
    for(char c : name)
        push(myStack, sp, c);
    std::cout << "the size: " << get_size(myStack, sp) << std::endl;
    while(sp > -1)
        std::cout << pop(myStack, sp) << std::endl;
    std::cout << "the size: " << get_size(myStack, sp) << std::endl;
    
    return 0;
}