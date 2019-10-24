

#include"Stack.hpp"

template<class T>
Stack<T>::Stack(){
    size = 0;
    bottomOfStack = nullptr;
    topOfStack = nullptr;
}

template<class T>
Stack<T>::Stack(T) : size(1){
    addDataAtEnd(bottomOfStack, topOfStack, T);
}

template<class T>
void Stack<T>::push(T){
    addDataAtEnd(bottomOfStack, topOfStack, T);
}

template<class T>
void Stack<T>::pop(){
    removeAtEnd(bottomOfStack, topOfStack);
}

template<class T>
int Stack<T>::getSize(){
    return size;
}

template<class T>
T Stack<T>::getTop(){
    if (!topOfStack)
        return topOfStack->data;
    return;
}
