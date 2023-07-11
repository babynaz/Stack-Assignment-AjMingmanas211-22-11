#ifndef NODE_H
#define NODE_H

class Node {
public:
	int value;
	Node* next = nullptr;

	Node(int value) { this->value = value; }
};

#endif
