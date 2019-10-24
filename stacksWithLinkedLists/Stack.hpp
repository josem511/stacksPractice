#ifndef STACK_HPP
#define STACK_HPP

#include"node.cpp"

template<class T>
class Stack{
    private:
        int size;
        node<T>* bottomOfStack;
        node<T>* topOfStack;
    public:
        Stack();
        Stack(T);
        void push(T);
        void pop();
        T getTop();
        int getSize();
};


template<class T>
Stack<T>::Stack(){
    size = 0;
    bottomOfStack = nullptr;
    topOfStack = nullptr;
}

template<class T>
Stack<T>::Stack(T t) : size(1){
    addDataAtEnd(bottomOfStack, topOfStack, t);
}

template<class T>
void Stack<T>::push(T t){
    addDataAtEnd(bottomOfStack, topOfStack, t);
    size++;
}

template<class T>
void Stack<T>::pop(){
    removeAtEnd(bottomOfStack, topOfStack);
    size--;
}

template<class T>
int Stack<T>::getSize(){
    return size;
}

template<class T>
T Stack<T>::getTop(){
    return topOfStack->data;
}

#endif