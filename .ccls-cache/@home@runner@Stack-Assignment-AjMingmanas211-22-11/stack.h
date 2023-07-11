#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <iostream>

class Stack {
private:
	Node* top = nullptr;

public:
	void pop();
	void push(int);
	bool empty();
	int getTop();
	void print();
};

bool Stack::empty() {
	return this->top == nullptr;
}

int Stack::getTop() {
	return this->empty() ? 0 : this->top->value;
}

void Stack::push(int n) {
	Node* newNode = new Node(n);

	if (this->top == nullptr) {
		this->top = newNode;
		return;
	}
	newNode->next = this->top;
	this->top = newNode;
}

void Stack::pop() {
	if (this->top == nullptr)
		return;

	Node* temp = this->top;
	this->top = this->top->next;
	delete temp;
}

void Stack::print() {
	for (Node* temp = this->top; temp != nullptr; temp = temp->next)
		std::cout << temp->value << "->";
	std::cout << "X" << std::endl;
}

#endif
