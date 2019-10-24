#ifndef NODE_CPP
#define NODE_CPP

#include <iostream>
#include <string>

template<class T>
struct node {
    T data;
    node * next = nullptr;
};

template<class T>
void traverse(node<T> * h) {
    while (h) {
        std::cout << h -> data << " ";
        h = h -> next;
    }
    std::cout << std::endl;
}

template<class T>
void addDataAtStart(node<T> * & h, node<T> * & t, T d) {
    node<T> * newnode = new node<T>;
    newnode -> data = d;
    newnode -> next = h;
    h = newnode;
    if (!t)
        t = newnode;
}

template<class T>
void addDataAtEnd(node<T> * & h, node<T> * & t, T d) {
    if (h == nullptr)
        addDataAtStart(h, t, d);
    else {
        node<T> * newnode = new node<T>;
        newnode -> data = d;
        t->next = newnode;
        t = newnode;
    }
}

template<class T>
void addDataInOrder(node<T> * & h, node<T> * & t, T d){
    //check if list is empty or d is smallest in list
    if (!h || d < h -> data)
        addDataAtStart(h, t, d);
    else if (d > t -> data)
        addDataAtEnd(h,t,d);
    else {
    //two temp pointers
    node<T> * ptr1 = h;
    node<T> * ptr2 = h -> next;

    //traverse until 2nd ptr gets to NULL or if its value is bigger than d
    while (ptr2 && ptr2 -> data < d) {
        ptr1 = ptr2;
        ptr2 = ptr2 -> next;
    }

    //allocate mem for new node
    node<T> * newnode = new node<T>;
    newnode -> data = d;

    //update ptrs
    ptr1 -> next = newnode;
    newnode -> next = ptr2;
    }


}

template<class T>
void removeAtStart(node<T> * & h, node<T> * & t) {
    if (!h)
        ;
    else if (h == t) {
        delete h;
        h = nullptr;
        t = nullptr;
    } else {
        node<T> * temp = h;
        h = h -> next;
        delete temp;
    }
}

template<class T>
void removeAtEnd(node<T> * & h, node<T> * & t){
    if (!h)
        ;
    else if (h == t) {
        removeAtStart(h,t);
    } else {
        node<T> * temp = h;
        while(temp -> next != t)
            temp = temp->next;
        t = temp;
        delete temp->next;
        temp->next = nullptr;
    }
}

template<class T>
void removeData(node<T> * & h, node<T> * & t, T d){
    if(h == nullptr)
        return;
    else if(h->data == d)
        removeAtStart(h,t);
    else if(t->data == d)
        removeAtEnd(h,t);
    else {
        node<T>* before_d = h;
        node<T>* after_d = nullptr;
        while(before_d->next != nullptr && before_d->next != t && before_d->next->data != d)
            before_d = before_d->next;
        if(before_d->next != nullptr && before_d->next->data == d){
            after_d = before_d->next->next;
            delete before_d->next;
            before_d->next = after_d;
        }
    }
}

#endif