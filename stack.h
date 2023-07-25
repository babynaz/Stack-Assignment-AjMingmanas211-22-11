#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <iostream>

typedef NODE* NodePtr;

class Stack {
private:
    NodePtr top;
    int size;
public:
    Stack(NodePtr = nullptr);
    ~Stack();
    int pop();
    void push(char);
};

Stack::Stack(NodePtr t) {
    if (t) {
        top = t;
        size = 1;
    }
    else {
        top = nullptr;
        size = 0;
    }
}

void Stack::push(char x) {
    NodePtr new_node = new NODE(x);
    if (new_node) {
        new_node->set_next(top);
        top = new_node;
        ++size;
    }
    else {
        std::cout << "No memory available for new nodes" << std::endl;
    }
}

int Stack::pop() {
    NodePtr t = top;
    int value;
    if (t) {
        value = t->get_value();
        top = t->get_next();
        --size;
        delete t;
        return value;
    }

    std::cout << "Stack underflow" << std::endl;
    return 0;
}

Stack::~Stack() {
    std::cout << "Clearing all stacks" << std::endl;
    NodePtr t = top;
    while (top) {
        top = top->get_next();
        delete t;
        t = top;
    }
}

#endif 